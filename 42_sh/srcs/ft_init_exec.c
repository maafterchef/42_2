/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 21:49:26 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/18 22:57:51 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	ft_init_process(t_list *job, t_env *e)
{
	t_list		*ptr;
	t_process	*ptr_pro;

	ptr = ((t_job *)job->content)->first_process;
	while (ptr)
	{
		ptr_pro = ptr->content;
		ptr_pro->path = ft_get_path(ptr_pro->cmd[0], ft_tab_env(e->env));
		if (!ptr_pro->path)
			return (ft_path_error(ptr_pro->cmd[0]));
		ptr = ptr->next;
	}
	ft_exec(job->content, e);
}

void		ft_init_exec(t_list *job, t_env *e)
{
	t_list	*tmp;

	tmp = job;
	while (tmp)
	{
		ft_init_process(tmp, e);
		tmp = tmp->next;
	}
}
