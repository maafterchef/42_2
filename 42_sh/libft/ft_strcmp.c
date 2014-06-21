/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:46:39 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/21 16:20:30 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		c;

	c = 0;
	if (s1 == NULL)
		return (1);
	while (s1[c] || s2[c])
	{
		if (s1[c] == s2[c])
			c++;
		else
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	}
	return (0);
}
