/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:38:13 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/19 00:28:23 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_set_r_redir2(char *fd)
{
	int		fd_dir;

	fd_dir = open(fd, O_WRONLY | O_CREAT, CREATE_MODE);
	dup2(fd_dir, STDOUT);
	close(fd_dir);
}

int		ft_set_r_redir(t_process *pro)
{
	if (pro->fd_dr_redir)
		return (open(pro->fd_r_redir, O_WRONLY | O_CREAT | O_TRUNC, CREATE_MODE));
	return (open(pro->fd_r_redir, O_WRONLY | O_CREAT, CREATE_MODE));
}