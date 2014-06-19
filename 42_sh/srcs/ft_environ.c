/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:33:00 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 20:15:02 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_list		*ft_get_env(void)
{
	extern char	**environ;
	int			i;
	t_list		*list;

	i = 0;
	list = NULL;
	if (*environ)
	{
		while (environ[i])
		{
			ft_lstpushback(&list, ft_lstnew(environ[i], ft_strlen(environ[i])));
			++i;
		}
		return (list);
	}
	ft_env_error();
	return (list);
}

char		**ft_tab_env(t_list *list)
{
	char	**env_tab;
	int		i;

	i = 0;
	env_tab = malloc(sizeof(char *) * (ft_lstsize(&list) + 1));
	while (list)
	{
		env_tab[i] = ft_strdup(list->content);
		++i;
		list = list->next;
	}
	env_tab[i] = 0;
	return (env_tab);
}

static void	ft_free_str(void *content, size_t nb)
{
	(void)nb;
	free(content);
}

void		ft_free_env(t_env *e)
{
	ft_lstdel(&(e->env), ft_free_str);
}
