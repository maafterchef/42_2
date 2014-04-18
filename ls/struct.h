/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 11:06:43 by mlingels          #+#    #+#             */
/*   Updated: 2014/04/15 11:08:29 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_options
{
	char		name;
	int			set;
}				t_options;

typedef struct	s_infos
{
	char		*name;
	mode_t		modes;
	nlink_t		nb_link;
	char		*owner;
	char		*group;
	off_t		size;
	time_t		time;
	dev_t		st_dev;
}				t_infos;

#endif
