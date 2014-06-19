/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 23:02:08 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/16 00:16:41 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		*ft_path_join(char *head, char *tail)
{
	char		*str;
	size_t		h;
	size_t		t;

	h = ft_strlen(head);
	t = ft_strlen(tail);
	str = ft_memalloc(h + t + 2);
	ft_strncpy(str, head, h);
	ft_strncpy(str + h, "/", 1);
	ft_strncpy(str + h + 1, tail, t);
	return (str);
}

static char		*ft_check_path(char **path_tab, char *cmd)
{
	size_t	i;
	char	*str;

	i = 0;
	while (path_tab[i])
	{
		str = !ft_strchr(cmd, '/') ? ft_path_join(path_tab[i], cmd) : cmd;
		if (access(str, X_OK) == 0)
		{
			ft_free_tab(path_tab);
			return (str);
		}
		++i;
		free(str);
	}
	return (0);
}

static char		*ft_absolute_path(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	else
		ft_path_error(cmd);
	return (0);
}

static char		*ft_get_path2(char *cmd)
{
	if (*cmd == '/')
		return (ft_absolute_path(cmd));
	return (ft_strdup("builtin"));
}

char			*ft_get_path(char *cmd, char **environ)
{
	char		**path_tab;
	size_t		c;

	c = 0;
	if (cmd)
	{
		if (ft_check_builtin(cmd) || *cmd == '/')
		{
			ft_free_tab(environ);
			return (ft_get_path2(cmd));
		}
		while (environ[c])
		{
			if (!ft_strncmp(environ[c], "PATH", 4))
			{
				path_tab = ft_strsplit(ft_strdup(environ[c]), ':');
				ft_free_tab(environ);
				return (ft_check_path(path_tab, cmd));
			}
			++c;
		}
	}
	ft_free_tab(environ);
	return (0);
}
