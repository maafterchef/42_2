/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:20:24 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		*ft_env_cat(char *key, char *value)
{
	char	*new_env;
	size_t	c;
	size_t	a;

	c = ft_strlen(key);
	a = ft_strlen(value);
	new_env = ft_memalloc(c + a + 2);
	ft_strncpy(new_env, key, c);
	ft_strncpy(new_env + c, "=", 1);
	ft_strncpy(new_env + c + 1, value, a);
	return (new_env);
}

void			ft_setenv(t_env *e, char **b_tab)
{
	t_list	*it;
	char	*new_env;

	it = e->env;
	if (ft_setenv_error(ft_tablen(b_tab), "setenv", 3))
	{
		new_env = ft_env_cat(b_tab[1], b_tab[2]);
		while (it)
		{
			if (!ft_strncmp(b_tab[1], it->content, ft_strlen(b_tab[1])))
			{
				ft_strcpy(it->content, new_env);
				break ;
			}
			it = it->next;
		}
		if (it == NULL)
			ft_lstpushback(&(e->env), ft_lstnew(new_env, ft_strlen(new_env)));
		free(new_env);
	}
}
