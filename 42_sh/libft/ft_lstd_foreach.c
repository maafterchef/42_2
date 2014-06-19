/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 22:14:16 by bboumend          #+#    #+#             */
/*   Updated: 2014/01/09 20:40:33 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstd_foreach(t_dlist *dlist, t_dlistf f, void *data)
{
	t_dlist	*tmp;

	if (dlist)
	{
		tmp = dlist;
		while (dlist->next != tmp)
		{
			f(dlist, data);
			dlist = dlist->next;
		}
		f(dlist, data);
	}
}
