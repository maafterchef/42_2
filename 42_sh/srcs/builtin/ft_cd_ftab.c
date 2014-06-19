/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_ftab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/02 18:34:56 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_root(t_env *e)
{
	if (!chdir("/"))
	{
		ft_env_modify("OLDPWD", e, ft_get_pwd("PWD", e));
		ft_env_modify("PWD", e, "/");
		return ;
	}
	ft_cd_error("/");
}

void	ft_home(t_env *e)
{
	char	*new_pwd;

	if (!(new_pwd = ft_get_pwd("HOME", e)))
		return ;
	if (!chdir(new_pwd))
	{
		ft_env_modify("OLDPWD", e, ft_get_pwd("PWD", e));
		ft_env_modify("PWD", e, new_pwd);
		free(new_pwd);
		return ;
	}
	ft_cd_error("HOME");
}

void	ft_old(t_env *e)
{
	char	*new_pwd;
	char	*user;

	new_pwd = ft_get_pwd("OLDPWD", e);
	user = 0;
	if (!chdir(new_pwd))
	{
		ft_env_modify("OLDPWD", e, ft_get_pwd("PWD", e));
		ft_env_modify("PWD", e, new_pwd);
		if (!(user = ft_get_pwd("USER", e)))
			user = ft_strdup("/");
		if (ft_strstr(new_pwd, user))
			ft_putendl(ft_strstr(new_pwd, user));
		else
			ft_putendl(new_pwd);
		free(user);
		free(new_pwd);
		return ;
	}
	ft_cd_error("OLDPWD");
}

void	ft_previous(t_env *e)
{
	size_t	i;
	char	*new_pwd;
	char	**pwd_tab;

	i = 0;
	if (!ft_strcmp(ft_get_pwd("PWD", e), "/"))
		return ;
	pwd_tab = ft_strsplit(ft_get_pwd("PWD", e), '/');
	*pwd_tab = ft_strjoin("/", *pwd_tab);
	while (pwd_tab[i])
		++i;
	free(pwd_tab[i - 1]);
	pwd_tab[i - 1] = 0;
	new_pwd = ft_strunion(pwd_tab, '/');
	if (!chdir(new_pwd))
	{
		ft_env_modify("OLDPWD", e, ft_get_pwd("PWD", e));
		ft_env_modify("PWD", e, new_pwd);
	}
	free(new_pwd);
	ft_free_tab(pwd_tab);
}

void	ft_dir(t_env *e, char *dir)
{
	char	*new_pwd;
	char	*tmp_pwd;

	if (!chdir(dir))
	{
		tmp_pwd = ft_strjoin(ft_get_pwd("PWD", e), "/");
		new_pwd = ft_strjoin(tmp_pwd, dir);
		ft_env_modify("OLDPWD", e, ft_get_pwd("PWD", e));
		ft_env_modify("PWD", e, new_pwd);
		free(tmp_pwd);
		free(new_pwd);
		return ;
	}
	ft_cd_error(dir);
}
