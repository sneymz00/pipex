/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:56:08 by camurill          #+#    #+#             */
/*   Updated: 2024/06/15 22:03:35 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	funtion_exe(char *ag, char **env)
{



void	child_process(int *p_fd, char **ag, char **env)
{
	int fd;

	fd = open_file(ag[1], 0)
	if (dup2(fd, STDIN_FILENO) < 0)
		ft_error(3);
	if (dup2(p_fd[1], STDOUT_FILENO) < 0)
		ft_error(3);
	close(p_fd[0]);
	funtion_exe(ag[2], env);
}

void	parent_process(int *p_fd, char **ag, char **env)
{
	int	fd;

	fd = open_file(ag[4], 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		ft_error(3);
	if (dup2(p_fd[0], STDIN_FILENO) < 0)
		ft_error(3);
	close(p_fd[1]);
	funtion_exe(ag[3], env);
}
