/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 18:11:30 by bboumend          #+#    #+#             */
/*   Updated: 2014/06/19 00:27:27 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

/*
** Includes
*/
# include "../libft/includes/libft.h"
# include <fcntl.h>

/*
** Defines
*/
# define PROMPT				"$> "
# define WRITE(fd, what)	write(fd, what, sizeof(what) - 1);
# define DAT_NORME			t_process **pro, char **job
# define CREATE_MODE		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/*
** Typedefs
*/
typedef struct s_process	t_process;

/*
** Base
*/
void				ft_read(void);
char				*ft_get_path(char *cmd, char **environ);

/*
** Pars
*/
typedef enum		e_token_type
{
	TOK_PIPE,
	TOK_L_REDIR,
	TOK_R_REDIR,
	TOK_DL_REDIR,
	TOK_DR_REDIR,
	WORD
}					t_token_type;

typedef struct		s_token
{
	char			*cmd;
	t_token_type	type;
	size_t			(*f)(t_process **pro, char **job, t_list **proc_lst, size_t *tab);
}					t_token;

size_t				ft_dl_redir(DAT_NORME, t_list **proc_lst, size_t *tab);
size_t				ft_dr_redir(DAT_NORME, t_list **proc_lst, size_t *tab);
size_t				ft_l_redir(DAT_NORME, t_list **proc_lst, size_t *tab);
size_t				ft_r_redir(DAT_NORME, t_list **proc_lst, size_t *tab);
size_t				ft_pipe(DAT_NORME, t_list **proc_lst, size_t *tab);
size_t				ft_end_dir(char *job);
size_t				ft_count_whitespace(char *job);

/*
** struc_control
*/
struct				s_process
{
	char			*path;
	char			**cmd;
	char			*fd_r_redir;
	char			fd_dr_redir;
	char			*fd_l_redir;
	char			fd_dl_redir;
};

typedef struct		s_job
{
	char			*command;
	t_list			*first_process;
	char			notified;
	int				fd[2];
}					t_job;

t_list				*ft_make_job(char *job);

/*
** Env
*/
typedef struct		s_env
{
	t_list			*env;
	int				fd_save;
}					t_env;

t_list				*ft_get_env(void);
char				**ft_tab_env(t_list *list);
void				ft_free_env(t_env *e);

/*
** Exec
*/
void				ft_exec(t_job *job, t_env *e);
void				ft_init_exec(t_list *job, t_env *e);
int					ft_set_r_redir(t_process *pro);
void				ft_set_r_redir2(char *fd);

/*
** Builtin
*/
typedef struct		s_cd
{
	char			*str;
	void			(*f)(t_env *e);
}					t_cd;
typedef struct		s_built
{
	char			*str;
	void			(*f)(t_env *e, char **b_tab);
}					t_built;

int					ft_check_builtin(char *cmd);
void				ft_builtin(char **cmd, t_env *e);
void				ft_unsetenv(t_env *e, char **b_tab);
void				ft_setenv(t_env *e, char **b_tab);
char				*ft_get_prompt(t_env *e);
void				ft_print_prompt(char *prompt);
void				ft_pid(t_env *e, char **b_tab);
void				ft_exit(t_env *e, char **b_tab);
void				ft_env(t_env *e, char **b_tab);
void				ft_echo(t_env *e, char **b_tab);
void				ft_cd(t_env *e, char **b_tab);
void				ft_array_cd(t_env *e, char *dir);
char				*ft_get_pwd(const char *name, t_env *e);
void				ft_env_modify(const char *path_name, t_env *e, char *str);
void				ft_dirtab(t_env *e, char **dir_tab);
void				ft_dir(t_env *e, char *dir);
void				ft_previous(t_env *e);
void				ft_old(t_env *e);
void				ft_home(t_env *e);
void				ft_root(t_env *e);

/*
** Error
*/
void				ft_path_error(char *cmd);
void				ft_error(char *name);
void				ft_env_error(void);
void				ft_cd_error(char *str);
int					ft_setenv_error(int i, char *name, int c);

#endif