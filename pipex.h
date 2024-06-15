/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:25:52 by camurill          #+#    #+#             */
/*   Updated: 2024/06/15 17:50:28 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include "libreries/libft/libft.h"

typedef struct s_pipe{
	char	**cmd;
	char	**path_cmd;
	
	int		fd1;
	int		fd2;
	char	ag1;
	char	ag2;
}			t_pipe;


/**MAIN**/
void    pipex(int fd1, int fd2, char **ag, char **env);

/**ERROR**/

#endif
