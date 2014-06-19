/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 00:07:32 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/15 23:53:48 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_path_error(char *cmd)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	if (cmd)
		ft_putendl_fd(cmd, 2);
	else
		ft_putendl_fd("parse error", 2);
}

void	ft_error(char *name)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": error", 2);
	exit(0);
}

void	ft_env_error(void)
{
	ft_putstr_fd("42sh: environ can't be found\n", 2);
	exit(0);
}
