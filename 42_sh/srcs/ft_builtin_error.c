/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:33:56 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:34:31 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_setenv_error(int i, char *name, int c)
{
	if (i < c)
	{
		ft_putstr_fd(name, 2);
		WRITE(2, ": missing arguments\n");
		return (0);
	}
	else if (i > c)
	{
		ft_putstr_fd(name, 2);
		WRITE(2, ": too many arguments\n");
		return (0);
	}
	return (1);
}

void	ft_cd_error(char *str)
{
	WRITE(2, "42sh: cd: no such file or directory: ");
	ft_putendl_fd(str, 2);
}
