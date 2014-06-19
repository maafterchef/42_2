/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 00:12:41 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/19 00:26:53 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	ft_exec_son(t_process *pro, int *fd, int opt, t_env *e)
{
	// if (pro->fd_r_redir)
	// 	fd[STDIN] = open(pro->fd_r_redir, O_RDONLY);
	// else
	dup2(e->fd_save, STDIN);
	if (opt == 1 || pro->fd_r_redir)
	{
		if (pro->fd_r_redir)
			fd[STDOUT] = ft_set_r_redir(pro);
		dup2(fd[STDOUT], STDOUT);
	}
	close(fd[STDIN]);
	execve(pro->path, pro->cmd, ft_tab_env(e->env));
}

static void	ft_exec_builtin(t_process *pro, int *fd, int opt, t_env *e)
{
	// if (pro->fd_r_redir)
		// fd[STDIN] = open(pro->fd_r_redir, O_RDONLY);
	// else
	dup2(e->fd_save, STDIN);
	if (opt == 1 || pro->fd_r_redir)
	{
		if (pro->fd_r_redir)
			fd[STDOUT] = open(pro->fd_r_redir, O_WRONLY | O_CREAT, CREATE_MODE);
		dup2(fd[STDOUT], STDOUT);
	}
	close(fd[STDIN]);
	ft_builtin(pro->cmd, e);
}

static void	ft_exec_cmd(t_list **tmp, t_job **job, t_env *e)
{
	pid_t	id;

	if ((id = fork()) == -1)
		ft_error("fork");
	if (id == 0)
	{
		if ((*tmp)->next)
			ft_exec_son((*tmp)->content, (*job)->fd, 1, e);
		else
			ft_exec_son((*tmp)->content, (*job)->fd, 0, e);
	}
	else
	{
		waitpid(id, 0, 0);
		e->fd_save = (*job)->fd[STDIN];
		(*tmp) = (*tmp)->next;
		close((*job)->fd[STDOUT]);
		if (pipe((*job)->fd) == -1)
			ft_error("pipe");
	}
}

static void	ft_new_exec(t_job *job, t_env *e)
{
	t_list		*tmp;
	t_process	*pro;

	tmp = job->first_process;
	pro = tmp->content;
	e->fd_save = 0;
	if (tmp->next)
	{
		while (tmp)
		{
			if (!ft_strcmp(((t_process*)tmp->content)->path, "builtin"))
			{
				ft_exec_builtin(tmp->content, job->fd, 0, e);
				tmp = tmp->next;
			}
			else
				ft_exec_cmd(&tmp, &job, e);
		}
		exit(0);
	}
	else
	{
		if (pro->fd_r_redir)
			ft_set_r_redir2(pro->fd_r_redir);
		execve(pro->path, pro->cmd, ft_tab_env(e->env));
	}
}

void		ft_exec(t_job *job, t_env *e)
{
	pid_t		id;
	t_process	*pro;

	pro = job->first_process->content;
	if (!((t_list*)job->first_process)->next)
	{
		if (!ft_strcmp(pro->path, "builtin"))
		{
			ft_builtin(pro->cmd, e);
			return ;
		}
	}
	if (pipe(job->fd) == -1)
		ft_error("pipe");
	if ((id = fork()) == -1)
		ft_error("fork");
	if (id == 0)
		ft_new_exec(job, e);
	else
	{
		close(job->fd[STDIN]);
		close(job->fd[STDOUT]);
		waitpid(id, 0, 0);
	}
}
