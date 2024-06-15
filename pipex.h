/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:25:52 by camurill          #+#    #+#             */
/*   Updated: 2024/06/15 22:00:30 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include "libreries/libft/libft.h"

typedef struct s_pipe{
	char	**cmd;
	char	**path_cmd;
	
	int		fd1; //ag[1]
	int		fd2; //ag[4]
	char	command1; //ag[2]
	char	command2; //ag[3]
}			t_pipe;


/**MAIN**/

/**UTILS**/
t_pipe	init_process(int fd1, int fd2, char **ag, char **env);

/**PROCESS**/
void	child_pocess(int *fd, char **ag, char **env);
void	parent_process(int *fd, char **ag, char **env);

/**ERROR**/
void	ft_error(int mod);

/**LIBFT**/
char	**ty_split(const char *text, char separate);

#endif
