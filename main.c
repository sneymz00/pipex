/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:38 by camurill          #+#    #+#             */
/*   Updated: 2024/06/20 15:33:15 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int mod)
{
	if (mod == 1)
		write(2, "Please, enter a correct number\n", 32);
	else if (mod == 2)
		perror("Fork: ");
	else if (mod == 3)
		write(2, "Error: ", 8);
	exit(1);
}

int	main(int ac, char **ag, char **env)
{
	int		fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		ft_error(1);
	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		ft_error(2);
	if (pid1 == 0)
		child_process(fd, ag, env);
	pid2 = fork();
	if (pid2 < 0)
		ft_error(2);
	if (pid2 == 0)
		parent_process(fd, ag, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid1, &status, 0);
	return (0);
}
