/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 00:58:59 by mlingels          #+#    #+#             */
/*   Updated: 2014/06/21 16:40:44 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_left(char **buff, t_env *e, t_pos *pos, t_hist **hist)
{
	(void)buff;
	(void)hist;
	(void)e;
	if (pos->pos_x > 0)
	{
		pos->pos_x--;
		tputs(MOVE_LEFT);
	}
}

void	ft_right(char **buff, t_env *e, t_pos *pos, t_hist **hist)
{
	(void)buff;
	(void)hist;
	(void)e;
	if (pos->pos_x < pos->cmd_len)
	{
		pos->pos_x++;
		tputs(MOVE_RIGHT);
	}
}

void	ft_up(char **buff, t_env *e, t_pos *pos, t_hist **hist)
{
	int	i;

	if (pos->ptr == *hist)
		return ;
	if (pos->ptr == NULL)
		pos->ptr = (*hist)->prev;
	else 
		pos->ptr = pos->ptr->prev;
	tputs(CB);
	tputs(CE);
	i = pos->pos_x + PROMPT_SIZE;
	while (i-- > 0)
		tputs(MOVE_LEFT);
	ft_print_prompt(ft_get_prompt(e));
	*buff = ft_strsub(pos->ptr->cmd, 0, ft_strlen(pos->ptr->cmd));
	ft_putstr(*buff);
	pos->pos_x = ft_strlen(*buff);
	pos->cmd_len = pos->pos_x;
}

void	ft_down(char **buff, t_env *e, t_pos *pos, t_hist **hist)
{
	int	i;

	if (pos->ptr == NULL)
		return ;
	tputs(CB);
	tputs(CE);
	i = pos->pos_x + PROMPT_SIZE;
	while (i-- > 0)
		tputs(MOVE_LEFT);
	ft_print_prompt(ft_get_prompt(e));
	if (pos->ptr == (*hist)->prev)
	{
		pos->ptr = NULL;
		*buff = NULL;
		pos->pos_x = 0;
		pos->cmd_len = 0;
	}
	else
	{
		pos->ptr = pos->ptr->next;
		*buff = ft_strsub(pos->ptr->cmd, 0, ft_strlen(pos->ptr->cmd));
		ft_putstr(*buff);
		pos->pos_x = ft_strlen(*buff);
		pos->cmd_len = pos->pos_x;
	}
}

void		ft_del(char **buff, t_env *e, t_pos *pos, t_hist **hist)
{
	char	*new;
	int		i;

	(void)hist;
	if (*buff[0] == 0)
		return ;
	if (pos->pos_x >= pos->cmd_len)
		pos->pos_x--;
	new = ft_del_char(pos->pos_x, *buff);
	free(*buff);
	*buff = new;
	tputs(CB);
	tputs(CE);
	pos->cmd_len--;
	i = pos->pos_x + PROMPT_SIZE;
	while (i-- > 0)
		tputs(MOVE_LEFT);
	ft_print_prompt(ft_get_prompt(e));
	ft_putstr(*buff);
	i = pos->cmd_len;
	while (i-- > pos->pos_x)
		tputs(MOVE_LEFT);
}
