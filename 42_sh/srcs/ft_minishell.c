/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 18:14:42 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/21 16:31:56 by mlingels         ###   ########.fr       */
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

static char		*ft_minishell(t_env *e)
{
	char	*buff;
	t_list	*job_lst;
	char	*c;

	c = ft_strnew(5);
	ft_bzero(c, 5);
	buff = NULL;
	while (*(unsigned int *)c != 10)
	{
		if (c[0])
			ft_get_input(c, &buff, e);
		ft_bzero(c, 5);
		read(0, c, 5);
	}
	ft_putchar('\n');
	ft_add_to_hist(buff, &(e->hist));
	job_lst = ft_pars(buff);
	ft_init_exec(job_lst, e);
	ft_lst_foreach(job_lst, ft_free_job, 0);
	return (buff);
}

void			ft_read(void)
{
	char			*line;
	t_env			e;
	struct termios	term;
	char			term_buff[2048];

	line = NULL;
	e.env = ft_get_env();
	e.hist = ft_create_elem(NULL);
	e.pos = (t_pos *)malloc(sizeof(t_pos));
	tgetent(term_buff, getenv("TERM"));
	tcgetattr(0, &term);
	ft_set_term(&term);
	ft_print_prompt(ft_get_prompt(&e));
	while (ft_strcmp(line, "exit") != 0)
	{
		if (line)
			free(line);
		e.pos->pos_x = 0;
		e.pos->cmd_len = 0;
		e.pos->ptr = NULL;
		line = ft_minishell(&e);
		ft_print_prompt(ft_get_prompt(&e));
	}
	ft_unset_term(&term);
	ft_free_env(&e);
}
