/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:38 by camurill          #+#    #+#             */
/*   Updated: 2024/06/05 16:54:57 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void ft_error(void)
{
	write(1, "Please, enter a correct number\n", 32);
	exit(1);
}

void	pipex(int fd1, int fd2, char **ag, char **env)
{
	int	id;
	int	n;

	ft_read(ag[1]);
	ag[2] = ft_apolo(); //Quiero un padre ejecutando en este
                            //pero antes quiero definir fork()
	ag[3] = ft_suiza; // quiero ejecutarlo en el hijo
	ft_restore() //limpiar y corregir


int main(int ac, char **ag, char **env)
{
	int	id;
	int	fd[2];
	int	n = 0;

	if (ac != 5)
		ft_error();
	if (pipe(fd) == -1)
		return (1);
	fd[0] = open(ag[1], O_RDONLY) // leeemos
	f[1] = open(ag[4], O_CREAT | O_RDWL | O_TRUC, 0644);
	if (fd[0] < 0 || f[1] < 0)
		return (-1);
	pipex(f1, f2, ag, envp);
	return (0);
}
