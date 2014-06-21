/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 15:21:35 by mlingels          #+#    #+#             */
/*   Updated: 2014/06/21 16:06:23 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_set_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

void		ft_unset_term(struct termios *term)
{
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
}
