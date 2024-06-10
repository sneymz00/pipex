/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:56:08 by camurill          #+#    #+#             */
/*   Updated: 2024/06/10 15:34:30 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_env(char **env)

void	child_process(int fd1, char cmd1)
{
	if (dup2(fd1, STDIN_FILENO) < 0)
		ft_error(3);
	if (dup2(fd[0], STDOUT_FILENO) < 0)
		ft_error(3);
	close(fd[0]);
	//env
	exit(EXIT_FAILURE);
}


void	parent_process(int fd2, char cmd2);
