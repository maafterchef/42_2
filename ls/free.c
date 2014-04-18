/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 09:44:53 by mlingels          #+#    #+#             */
/*   Updated: 2014/04/18 09:48:38 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free(t_infos *entry_list, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(entry_list[j].name);
		entry_list[j].name = NULL;
		j++;
	}
	free(entry_list);
	entry_list = NULL;
}
