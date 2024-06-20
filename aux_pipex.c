/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:56:25 by camurill          #+#    #+#             */
/*   Updated: 2024/06/20 15:53:23 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_mat(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	open_file(char *file, int type)
{
	int	fd;

	if (type == 0)
		fd = open(file, O_RDONLY, 0777);
	else if (type == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		close(0);
	return (fd);
}

char	*get_env(char **env, char *name)
{
	char	*sub;
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (my_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**path_total;
	char	*path_aux;
	char	**aux;

	i = 0;
	path_total = ty_split(get_env(env, "PATH"), ':');
	aux = ty_split(cmd, ' ');
	while (path_total[i])
	{
		path_aux = my_strjoin(path_total[i], "/");
		exec = my_strjoin(path_aux, aux[0]);
		if (access(exec, F_OK) == 0 && access(exec, X_OK) == 0)
		{
			free_mat(aux);
			return (exec);
		}
		i++;
		free(exec);
		free(path_aux);
	}
	free_mat(path_total);
	free_mat(aux);
	return (cmd);
}
/*
int main(int ac, char **ag, char **env)
{
	char **split;
	//char env_long[120] = get_env(env, "PATH");

	int i = 0;
	//printf("%s\n\n", env_long);
	split = ty_split(get_env(env, "PATH"), ':');
	printf("%s\n", split[0]);
	while (1)
	{
		printf("%s\n", split[i]);
		i++;
		if (split[i] == NULL)
			break ;
	}
	return (0);
}*/
