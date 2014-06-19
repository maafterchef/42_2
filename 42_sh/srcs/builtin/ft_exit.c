/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/17 19:51:34 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_sh.h"

void	ft_exit(t_env *e, char **b_tab)
{
	ft_free_lst(&e->env);
	if (b_tab[1])
		exit(ft_atoi(b_tab[1]));
	exit(0);
}
