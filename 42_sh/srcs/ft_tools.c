/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 18:47:50 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/18 19:28:10 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

size_t		ft_end_dir(char *job)
{
	size_t	count;

	count = 0;
	ft_ignore_whitespace(&job);
	while (job[count] && job[count] != ' ' 
					  && job[count] != '|'
					  && job[count] != '<'
					  && job[count] != '>')
	{
		count++;
	}
	return (count + 1);
}

size_t		ft_count_whitespace(char *job)
{
	size_t	c;

	c = 0;
	while (*job == ' ' || *job == '\t' || *job == '|')
	{
		++job;
		++c;
	}
	if (*job == '\0')
		return (0);
	return (c);
}
