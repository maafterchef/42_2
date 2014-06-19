/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:20:37 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_sh.h"

void	ft_env(t_env *e, char **b_tab)
{
	t_list	*env;

	env = e->env;
	if (ft_tablen(b_tab) != 1)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(b_tab[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else
	{
		while (env)
		{
			ft_putendl(env->content);
			env = env->next;
		}
	}
}
