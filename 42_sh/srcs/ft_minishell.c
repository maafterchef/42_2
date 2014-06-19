/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 18:14:42 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/18 22:43:21 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static t_list	*ft_pars(char *line)
{
	char	**job_tab;
	t_list	*job_lst;
	size_t	i;

	i = 0;
	job_lst = NULL;
	ft_ignore_whitespace(&line);
	job_tab = ft_strsplit(line, ';');
	while (job_tab[i])
	{
		ft_lstpushback(&job_lst, ft_make_job(job_tab[i]));
		++i;
	}
	return (job_lst);
}

static void		ft_free_proc(t_list *list, void *data)
{
	t_process	*pro;

	(void)data;
	pro = list->content;
	free(pro->path);
	ft_free_tab(pro->cmd);
	free(pro);
}

static void		ft_free_job(t_list *list, void *data)
{
	t_job	*j;

	(void)data;
	j = list->content;
	free(j->command);
	ft_lst_foreach(j->first_process, ft_free_proc, 0);
	free(j->first_process);
	free(j);
}

static void		ft_minishell(char *line, t_env *e)
{
	t_list	*job_lst;

	job_lst = ft_pars(line);
	ft_init_exec(job_lst, e);
	ft_lst_foreach(job_lst, ft_free_job, 0);
}

void			ft_read(void)
{
	char	*line;
	t_env	e;

	line = NULL;
	e.env = ft_get_env();
	ft_print_prompt(ft_get_prompt(&e));
	while (get_next_line(0, &line))
	{
		ft_minishell(line, &e);
		ft_print_prompt(ft_get_prompt(&e));
		free(line);
	}
	ft_free_env(&e);
}
