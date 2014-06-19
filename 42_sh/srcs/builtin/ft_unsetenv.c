/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:20:23 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_sh.h"

static void		ft_free_str(void *content, size_t nb)
{
	(void)nb;
	free(content);
}

static void		ft_unsetenv_error(char *name)
{
	ft_putstr_fd("unsetenv: no name found: ", 2);
	ft_putendl_fd(name, 2);
}

static void		ft_ptr_switch(t_env *e, t_list *tmp, t_list *it)
{
	if (tmp)
		tmp->next = it->next;
	else
		e->env = it->next;
}

void			ft_unsetenv(t_env *e, char **b_tab)
{
	t_list	*it;
	t_list	*tmp;

	it = e->env;
	tmp = 0;
	if (!ft_setenv_error(ft_tablen(b_tab), "unsetenv", 2))
		return ;
	while (it)
	{
		if (!ft_strncmp(b_tab[1], it->content, ft_strlen(b_tab[1])))
		{
			ft_ptr_switch(e, tmp, it);
			ft_lstdelone(&it, ft_free_str);
			return ;
		}
		tmp = it;
		it = it->next;
	}
	ft_unsetenv_error(b_tab[1]);
}
