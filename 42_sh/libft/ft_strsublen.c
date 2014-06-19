/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsublen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 19:31:50 by bboumend          #+#    #+#             */
/*   Updated: 2013/12/23 19:53:28 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strsublen(const char *str, int start, char c)
{
	int		i;

	i = 0;
	while (str[start] && str[start] != c)
	{
		++start;
		++i;
	}
	return (i);
}
