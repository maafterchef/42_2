/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 09:41:59 by mlingels          #+#    #+#             */
/*   Updated: 2014/04/18 09:43:04 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_puterror(char *str)
{
	ft_putendl("ft_ls: error");
	ft_putstr(str);
	ft_putendl(" : file error");
}
