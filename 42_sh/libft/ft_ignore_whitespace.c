/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ignore_whitespace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 20:36:43 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/15 20:36:57 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ignore_whitespace(char **line)
{
	while (**line == ' ' || **line == '\t')
		++(*line);
	if (**line == '\0')
		return (0);
	return (1);
}
