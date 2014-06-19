/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 20:31:29 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_echo(t_env *e, char **b_tab)
{
	size_t	i;

	(void)e;
	i = 1;
	if (b_tab[1])
	{
		if (!ft_strcmp(b_tab[1], "-n"))
			++i;
		while (b_tab[i])
		{
			ft_putstr(b_tab[i]);
			ft_putchar(' ');
			++i;
		}
		if (ft_strcmp(b_tab[1], "-n"))
			ft_putchar('\n');
	}
}
