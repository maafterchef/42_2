/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:20:27 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_pid(t_env *e, char **b_tab)
{
	pid_t	pid;

	(void)e;
	(void)b_tab;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
}
