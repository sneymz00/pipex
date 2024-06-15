/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:38 by camurill          #+#    #+#             */
/*   Updated: 2024/06/15 17:52:55 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void ft_error(int mod)
{
	if (mod == 1);
		write(2, "Please, enter a correct number\n", 32);
	if (mod == 2)
		write(2, "Error Fork", 1);
	exit(1);
}

void	pipex(int fd1, int fd2, cha:r **ag, char **env)
{
	pid_t	father;

	init_struct(fd1, fd2, ag, env);
	father = fork();
	if (father < 0)
		ft_error(2);
	if (!father)
		child_process(fd1,  ag[2]); //cmd1
	else
		parent_process(fd2, ag[3]); //cmd2
	if (execve(pipe->cmd, pipe->path_cmd, NULL) = -1)
	{
		funtion_free(s_pipe); //liberamos cmd y path
		close(fd[1]);
		close(fd[0]);
		perror("");
	}
}


int main(int ac, char **ag, char **env)
{
	int	fd[2];
	int	n = 0;

	if (ac != 5)
		ft_error(1);
	if (pipe(fd) == -1)
		return (1);
	fd[0] = open(ag[1], O_RDONLY);
	fd[1] = open(ag[4], O_CREAT | O_RDWL | O_TRUC, 0644);
	if (fd[0] < 0 || f[1] < 0)
		return (-1);
	pipe(fd[0], fd[1], ag, env);
	return (0);
}
