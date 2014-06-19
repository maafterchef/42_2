/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 19:06:46 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/19 00:18:36 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static const t_token	g_tok[] = {
	{"<<", TOK_DL_REDIR, ft_dl_redir},
	{">>", TOK_DR_REDIR, ft_dr_redir},
	{"<", TOK_L_REDIR, ft_l_redir},
	{">", TOK_R_REDIR, ft_r_redir},
	{"|", TOK_PIPE, ft_pipe}};

static char		*ft_del_tab(char *job)
{
	size_t		s;
	char		*new_job;

	s = 0;
	new_job = ft_memalloc(ft_strlen(job) + 1);
	while (job[s])
	{
		if (job[s] == '\t')
			new_job[s] = ' ';
		else
			new_job[s] = job[s];
		++s;
	}
	free(job);
	return (new_job);
}

static void		ft_init_process(t_process **pro, t_list **proc_lst)
{
	*pro = ft_memalloc(sizeof(t_process));
	(*pro)->path = NULL;
	(*pro)->fd_r_redir = NULL;
	(*pro)->fd_dr_redir = 0;
	(*pro)->fd_l_redir = NULL;
	(*pro)->fd_dl_redir = 0;
	*proc_lst = NULL;
}

static size_t	*ft_init_i_tab(size_t start, size_t i)
{
	size_t	*tab;

	tab = ft_memalloc(2);
	tab[0] = start;
	tab[1] = i;
	return (tab);
}

static t_list	*ft_make_process(char *job, size_t i, size_t start, size_t c)
{
	t_process	*pro;
	t_list		*proc_lst;
	size_t		*tab;

	ft_init_process(&pro, &proc_lst);
	job = ft_del_tab(job);
	while (job[i])
	{
		c = 0;
		while (c < (sizeof(g_tok) / sizeof(t_token)))
		{
			if (!ft_strncmp(&job[i], g_tok[c].cmd, ft_strlen(g_tok[c].cmd)))
			{
				tab = ft_init_i_tab(start, i);
				start = g_tok[c].f(&pro, &job, &proc_lst, tab);
				start += ft_count_whitespace(job + start);
				i = start;
				break ;
			}
			++c;
		}
		++i;
	}
	if (job[start] && start < ft_strlen(job))
	{
		pro->cmd = ft_strsplit(ft_strsub(job, start, i - start), ' ');
		ft_lstpushback(&proc_lst, ft_lstnew(pro, sizeof(t_process)));
	}
	return (proc_lst);
}

t_list			*ft_make_job(char *job)
{
	t_job		*job_s;
	size_t		i;
	size_t		start;
	size_t		c;

	i = 0;
	c = 0;
	start = 0;
	job_s = ft_memalloc(sizeof(t_job));
	job_s->command = ft_strdup(job);
	job_s->first_process = ft_make_process(job, i, start, c);
	job_s->notified = 0;
	return (ft_lstnew(job_s, sizeof(t_job)));
}
