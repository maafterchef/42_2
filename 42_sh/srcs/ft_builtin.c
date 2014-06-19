/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:40:48 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 20:41:15 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static const t_built	g_tab[] = {
	{"cd", ft_cd},
	{"exit", ft_exit},
	{"env", ft_env},
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
	{"echo", ft_echo},
	{"pid", ft_pid}};

int		ft_check_builtin(char *cmd)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_tab) / sizeof(t_built))
	{
		if (!ft_strcmp(g_tab[i].str, cmd))
			return (1);
		++i;
	}
	return (0);
}

void	ft_builtin(char **cmd, t_env *e)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_tab) / sizeof(t_built))
	{
		if (!ft_strcmp(g_tab[i].str, cmd[0]))
		{
			g_tab[i].f(e, cmd);
			return ;
		}
		++i;
	}
}
