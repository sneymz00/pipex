/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:38 by camurill          #+#    #+#             */
/*   Updated: 2024/06/19 19:13:38 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int mod)
{
	if (mod == 1)
		write(2, "Please, enter a correct number\n", 32);
	else if (mod == 2)
		write(2, "Error Fork", 1);
	else if (mod == 3)
		write(2, "Error: ", 8);
	exit(1);
}

int	main(int ac, char **ag, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		ft_error(1);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		ft_error(2);
	if (!pid)
		child_process(fd, ag, env);
	parent_process(fd, ag, env);
	return (0);
}
