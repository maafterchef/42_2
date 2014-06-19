/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 20:05:13 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/19 00:27:46 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

size_t	ft_dl_redir(t_process **pro, char **job, t_list **proc_lst, size_t *tab)
{
	(void)pro;
	(void)job;
	(void)proc_lst;
	free(tab);
	return (0);
}

size_t	ft_dr_redir(t_process **pro, char **job, t_list **proc_lst, size_t *tab)
{
	(*pro)->fd_dr_redir = 1;
	return (ft_r_redir(pro, job, proc_lst, tab));
}

size_t	ft_l_redir(t_process **pro, char **job, t_list **proc_lst, size_t *tab)
{
	(void)pro;
	(void)job;
	(void)proc_lst;
	free(tab);
	return (0);
}

size_t	ft_r_redir(t_process **pro, char **job, t_list **proc_lst, size_t *tab)
{
	size_t	i;
	size_t	start;
	char	*dir;
	size_t	space_nb;

	start = tab[0];
	i = tab[1];
	free(tab);
	space_nb = ft_count_whitespace(*job + i + 1);
	dir = ft_strsub(*job, i + 1 + space_nb, ft_end_dir(&job[0][i + 1]));
	ft_ignore_whitespace(&dir);
	(*pro)->fd_r_redir = dir;
	(*pro)->cmd = ft_strsplit(ft_strsub(*job, start, i - start), ' ');
	ft_lstpushback(proc_lst, ft_lstnew(*pro, sizeof(t_process)));
	return (ft_end_dir(&job[0][i + 1]) + i + 1 + space_nb);
}

size_t	ft_pipe(t_process **pro, char **job, t_list **proc_lst, size_t *tab)
{
	size_t	i;
	size_t	start;

	start = tab[0];
	i = tab[1];
	free(tab);
	(*pro)->fd_r_redir = NULL;
	(*pro)->cmd = ft_strsplit(ft_strsub(*job, start, i - start), ' ');
	ft_lstpushback(proc_lst, ft_lstnew(*pro, sizeof(t_process)));
	return (i + 1);
}
