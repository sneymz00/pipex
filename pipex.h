/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:25:52 by camurill          #+#    #+#             */
/*   Updated: 2024/06/20 16:33:59 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libreries/libft/libft.h"

/**UTILS**/
char	*get_env(char **env, char *name);
char	*get_path(char *cmd, char **env);
int		open_file(char *ag, int type);

/**PROCESS**/
void	funtion_exe(char *ag, char **env);
void	child_process(int *fd, char **ag, char **env);
void	parent_process(int *fd, char **ag, char **env);

/**ERROR**/
void	ft_error(int mod, char *ag);
void	free_mat(char **matrix);

/**LIBFT**/
char	**ty_split(const char *text, char separate);
char	*my_strjoin(const char *s1, const char *s2);
int		my_strcmp(char *cmp, char *src);

#endif
