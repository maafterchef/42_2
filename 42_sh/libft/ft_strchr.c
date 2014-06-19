/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:47:43 by bboumend          #+#    #+#             */
/*   Updated: 2013/11/24 19:22:28 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	c2;

	index = 0;
	c2 = c;
	while (s[index])
	{
		if (s[index] == c2)
			return ((char*)&s[index]);
		index++;
	}
	if (s[index] == c2)
		return ((char*)&s[index]);
	return (0);
}
