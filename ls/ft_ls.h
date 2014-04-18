/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlingels <mlingels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:42:14 by mlingels          #+#    #+#             */
/*   Updated: 2014/04/18 09:53:00 by mlingels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <libft.h>
# include "struct.h"
# define OPT_NB 5

void	ft_print_dirname(int i, int argc, char *str);
void	ft_read_args(t_options *list, int argc, char **argv);
void	ft_unfound_error(char *name, char *path);
void	ft_permission_denied(char *name, char *path);
int		ft_ls(char *dir);
int		ft_is_valid_dir(char *str, DIR **res, char **path);
int		ft_is_dir(char *str);
void	ft_ls_dir(DIR *ls_dir, t_options *list, int nb, char *path);
void	ft_list_options(t_options *list);
void	ft_add_opt(char c, t_options *list, int i);
int		ft_check_args(char *str, t_options *list);
void	ft_opt_error(char c, t_options *list);
int		ft_save_stats(t_infos *entry, char *path, t_options *list, int i);
char	*ft_joinpath(char *path, char *entry);
void	ft_sort_entries(t_infos *entry_list, int i, t_options *list, char *dir);
void	ft_print_entries(t_infos *e_list, int i, t_options *list, char *dir);
void	ft_swap_entries(t_infos *entry_list, int i, int j, t_options *list);
void	ft_print_type(mode_t modes);
void	ft_print_rights(mode_t modes);
void	ft_print_rights_end(mode_t modes);
void	ft_get_link_spaces(t_infos *entry_list, int i, int j);
int		ft_digitlen(int i);
void	ft_get_owner_spaces(t_infos *entry_list, int i, int j);
int		ft_spacelen(char *str);
void	ft_get_size_spaces(t_infos *entry_list, int i, int j, int ret);
void	ft_print_blocks(int nb_blocks, t_options *list);
void	ft_ls_dev(t_options *list, int nb, DIR *ls_dir);
void	ft_get_group_spaces(t_infos *entry_list, int i, int j);
int		ft_get_major_spaces(t_infos *entry_list, int i, int j);
int		ft_get_minor_spaces(t_infos *entry_list, int i, int j);
void	ft_print_link(char *name, char *path);
void	ft_ls_current(t_options *list);
int		ft_is_dev(t_infos *entry_list, int i);
void	ft_recursive(char *path, t_options *list);
int		ft_dir_permissions(char *path);
int		ft_sort_time_entries(t_infos *entry_list, int i, t_options *list);
int		ft_check(int i, t_options *list);
void	ft_find_file(char *str);
char	*ft_find_path(char **str);
char	*ft_get_owner(struct passwd *id, uid_t st_uid);
char	*ft_get_grp(struct group *grp);
void	ft_valid_entries(t_infos *e_list, int i, t_options *list, char *dir);
void	ft_puterror(char *str);
void	ft_free(t_infos *entry_list, int i);

#endif
