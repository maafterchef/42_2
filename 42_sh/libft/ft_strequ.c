/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:41:31 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 20:35:18 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strequ("a", "a") -> 1
** ft_strequ("a", "b") -> 0
** ft_strequ(NULL, NULL) -> 1
** ft_strequ("a", NULL) -> 0
** ft_strequ(NULL, "a") -> 0
*/

int		ft_strequ(const char *s1, const char *s2)
{
	if (!s2 ^ !s1)
		return (0);
	else if (!s1 && !s2)
		return (1);
	return (ft_strcmp(s1, s2));
}
