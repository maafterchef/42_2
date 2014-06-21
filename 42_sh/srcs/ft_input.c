/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 14:54:55 by mlingels          #+#    #+#             */
/*   Updated: 2014/06/21 16:42:19 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char	*ft_add_input(char *c, char *buff, int pos)
{
	char	*new;
	size_t	len;

	if (buff == NULL)
		len = 0;
	else
		len = ft_strlen(buff);
	new = (char *)malloc(sizeof(char) * (len + 2));
	if (new)
	{
		if (buff != NULL)
			(void)ft_strncpy(new, buff, pos);
		new[pos] = *c;
		if (buff != NULL)
			(void)ft_strncpy(&new[pos + 1], &buff[pos], len - pos);
		new[len + 1] = 0;
	}
	return (new);
}

void		ft_get_input(char *c, char **buff, t_env *e)
{
	int				i;
	static t_func	list[] =
	
	{
	{UP, &ft_up},
	{DOWN, &ft_down},
	{LEFT, &ft_left},
	{RIGHT, &ft_right},
	{DEL, &ft_del},
	{BCKSPCE, &ft_del},
	};
	i = 0;
	while (i < 6)
	{
		if (*(unsigned int *)c == list[i].name)
		{
			list[i].ptr(buff, e, e->pos, &(e->hist));
			return ;
		}
		i++;
	}
	*buff = ft_add_input(c, *buff, e->pos->pos_x);
	e->pos->cmd_len++;
	ft_print_str(*buff, e->pos);
}

char		*ft_del_char(int pos, char *str)
{
	char	*new;
	size_t	len;

	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * len);
	if (new)
	{
		(void)ft_strncpy(new, str, pos);
		(void)ft_strncpy(&new[pos], &str[pos + 1], len - pos);
		new[len] = 0;
	}
	return (new);
}

int			tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void		ft_print_str(char *str, t_pos *pos)
{
	int		i;

	tputs(CE);
	ft_putstr(&str[pos->pos_x]);
	pos->pos_x++;
	i = pos->cmd_len;
	while (i-- > pos->pos_x)
		tputs(MOVE_LEFT);
}
