/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 21:02:52 by mlingels          #+#    #+#             */
/*   Updated: 2014/04/18 09:53:27 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_find_path(char **str)
{
	int		i;
	char	*ptr;

	ptr = *str;
	i = ft_strlen(ptr);
	i--;
	while (i >= 0 && ptr[i] != '/')
		i--;
	if (i > 0)
	{
		ptr = ft_strsub(*str, 0, i);
		*str = ft_strsub(*str, i + 1, ft_strlen(*str));
	}
	else
		ptr = ".";
	return (ptr);
}

int		ft_check_args(char *str, t_options *list)
{
	int	i;
	int	verif;

	str++;
	while (*str)
	{
		i = 0;
		verif = 0;
		while (i < OPT_NB)
		{
			if (list[i].name == *str)
			{
				list[i].set = 1;
				verif = 1;
			}
			i++;
		}
		if (verif == 0)
		{
			ft_opt_error(*str, list);
			return (0);
		}
		str++;
	}
	return (1);
}

char	*ft_get_owner(struct passwd *id, uid_t st_uid)
{
	if (id)
		return (id->pw_name);
	else
		return (ft_itoa(st_uid));
}

char	*ft_get_grp(struct group *grp)
{
	if (grp)
		return (grp->gr_name);
	else
		return (NULL);
}

void	ft_valid_entries(t_infos *e_list, int i, t_options *list, char *dir)
{
	int	j;
	int	check;

	check = 0;
	j = 0;
	while (j < i)
	{
		if (e_list[j].group == NULL)
			check = 1;
		j++;
	}
	if (check == 0)
		ft_print_entries(e_list, i, list, dir);
	else
	{
		j = 0;
		while (j < i)
		{
			ft_putstr("ls: ");
			ft_putstr(e_list[j].name);
			ft_putendl(": Permission denied");
			j++;
		}
		ft_free(e_list, i);
	}
}
