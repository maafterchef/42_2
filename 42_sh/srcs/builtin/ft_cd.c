/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:21:43 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_sh.h"

static const t_cd	g_cd_tab[] =
{
	{"~", ft_home},
	{"-", ft_old},
	{"..", ft_previous},
	{"/", ft_root}
};

void			ft_env_modify(const char *path_name, t_env *e, char *str)
{
	t_list	*it;
	size_t	c;

	it = e->env;
	c = ft_strlen(path_name);
	while (it)
	{
		if (!ft_strncmp(path_name, it->content, c))
		{
			ft_strncpy((it->content + c + 1), str, ft_strlen(str) + 1);
			break ;
		}
		it = it->next;
	}
}

char			*ft_get_pwd(const char *name, t_env *e)
{
	t_list	*it;
	char	*str;
	size_t	n;

	str = 0;
	it = e->env;
	n = ft_strlen(name);
	while (it)
	{
		if (!ft_strncmp(name, it->content, n))
		{
			str = ft_strsub(it->content, n + 1, ft_strlen(it->content) - n + 1);
			break ;
		}
		it = it->next;
	}
	return (str);
}

static void		ft_check_var(const char *name, t_env *e)
{
	char	**b_tab;
	char	*pwd;

	if (!ft_get_pwd(name, e))
	{
		pwd = getcwd(0, 0);
		b_tab = ft_memalloc(4);
		b_tab[0] = ft_strdup("setenv");
		b_tab[1] = ft_strdup(name);
		b_tab[2] = ft_strdup(pwd);
		b_tab[3] = 0;
		ft_setenv(e, b_tab);
		ft_free_tab(b_tab);
	}
}

void			ft_array_cd(t_env *e, char *dir)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_cd_tab) / sizeof(t_cd))
	{
		if (!ft_strequ(g_cd_tab[i].str, dir))
		{
			g_cd_tab[i].f(e);
			return ;
		}
		++i;
	}
	ft_dir(e, dir);
}

void			ft_cd(t_env *e, char **b_tab)
{
	char	**dir_tab;

	ft_check_var("PWD", e);
	ft_check_var("OLDPWD", e);
	if (b_tab[1])
	{
		if (*b_tab[1] == '/')
		{
			dir_tab = ft_memalloc(2);
			*dir_tab = ft_strdup(b_tab[1]);
			dir_tab[1] = '\0';
		}
		else
			dir_tab = ft_strsplit(b_tab[1], '/');
		ft_dirtab(e, dir_tab);
		ft_free_tab(dir_tab);
	}
	else
		ft_home(e);
}
