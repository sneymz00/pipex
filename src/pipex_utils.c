/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:56:08 by camurill          #+#    #+#             */
/*   Updated: 2024/07/03 17:02:32 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	find_command(char *str, char find)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] == find)
			return (1);
		i++;
	}
	return (0);
}

void	funtion_exe(char *ag, char **env)
{
	char	**aux;
	char	*path;

	aux = ty_split(ag, ' ');
	if (!aux)
	{
		write(2, "zsh: permission denied:\n", 25);
		exit(126);
	}
	if (find_command(aux[0], '/') > 0)
		path = aux[0];
	else
		path = get_path(aux[0], env);
	if (!path)
	{
		write(2, "pipex: command not found:\n", 27);
		free_mat(aux);
		exit(127);
	}
	if (execve(path, aux, env) == -1)
	{
		perror("pipex: ");
		free_mat(aux);
		exit(126);
	}
}

void	child_process(int *p_fd, char **ag, char **env)
{
	int	fd;

	fd = open_file(ag[1], 0);
	if (dup2(fd, STDIN_FILENO) < 0)
		ft_error(3, ag[1]);
	if (dup2(p_fd[1], STDOUT_FILENO) < 0)
		ft_error(3, ag[4]);
	close(p_fd[0]);
	funtion_exe(ag[2], env);
}

void	parent_process(int *p_fd, char **ag, char **env)
{
	int	fd;

	if (open(ag[1], O_RDONLY) == -1)
	{
		open(ag[4], O_CREAT, 0644);
		exit(0);
	}
	fd = open_file(ag[4], 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		ft_error(3, ag[1]);
	if (dup2(p_fd[0], STDIN_FILENO) < 0)
		ft_error(3, ag[4]);
	close(p_fd[1]);
	funtion_exe(ag[3], env);
}
