/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 19:15:49 by bboumend          #+#    #+#             */
/*   Updated: 2014/05/18 19:20:25 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		*ft_make_prompt(char *prompt, char *login)
{
	char	*tmp;

	tmp = (*prompt == '/' ? ft_strdup(prompt + 1) : ft_strdup(prompt));
	free(prompt);
	prompt = ft_strjoin(" -> ", tmp);
	free(tmp);
	tmp = (*prompt == '/' ? ft_strdup(prompt + 1) : ft_strdup(prompt));
	free(prompt);
	prompt = ft_strjoin(login, tmp);
	free(tmp);
	tmp = (*prompt == '/' ? ft_strdup(prompt + 1) : ft_strdup(prompt));
	free(prompt);
	prompt = ft_strjoin(tmp, "  % ");
	free(tmp);
	return (prompt);
}

static char		*ft_array(char *login, char **pwd_tab, t_env *e)
{
	size_t	i;
	char	*prompt;

	i = 0;
	prompt = 0;
	while (pwd_tab[i])
	{
		if (!ft_strcmp(login, pwd_tab[i]))
		{
			if (pwd_tab[++i])
				prompt = ft_strunion(&pwd_tab[i], '/');
			else
				prompt = ft_strdup("~");
			prompt = ft_make_prompt(prompt, login);
			return (prompt);
		}
		++i;
	}
	return (ft_make_prompt(ft_get_pwd("PWD", e), login));
}

void			ft_print_prompt(char *prompt)
{
	ft_putstr(prompt);
	free(prompt);
}

char			*ft_get_prompt(t_env *e)
{
	char	*prompt;
	char	*login;
	char	**pwd_tab;
	char	*pwd;

	prompt = 0;
	if (!(login = ft_get_pwd("USER", e)))
		return (ft_strdup(PROMPT));
	if (!(pwd = ft_get_pwd("PWD", e)))
		return (ft_strdup(PROMPT));
	pwd_tab = ft_strsplit(pwd, '/');
	free(pwd);
	prompt = ft_array(login, pwd_tab, e);
	ft_free_tab(pwd_tab);
	free(login);
	return (prompt);
}
