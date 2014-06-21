/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 15:10:32 by mlingels          #+#    #+#             */
/*   Updated: 2014/06/21 16:15:21 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_hist		*ft_create_elem(char *str)
{
	t_hist	*new;

	new = (t_hist *)malloc(sizeof(t_hist));
	if (new)
	{
		if (str)
			new->cmd = ft_strsub(str, 0, ft_strlen(str));
		else
			new->cmd = NULL;
		new->next = new;
		new->prev = new;
	}
	return (new);
}

void		ft_add_to_hist(char *str, t_hist **start)
{
	t_hist	*tmp;
	t_hist	*new;

	tmp = *start;
	if (!((*start)->cmd))
		tmp->cmd = ft_strsub(str, 0, ft_strlen(str));
	else
	{
		while (tmp->next != *start)
			tmp = tmp->next;
		new = ft_create_elem(str);
		new->prev = tmp;
		tmp->next = new;
		new->next = *start;
		(*start)->prev = new;
	}
}
