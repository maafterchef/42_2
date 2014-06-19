/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:21:15 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_dirtab(t_env *e, char **dir_tab)
{
	size_t	i;

	i = 0;
	while (dir_tab[i])
	{
		if (ft_strcmp(dir_tab[i], "."))
			ft_array_cd(e, dir_tab[i]);
		++i;
	}
}
