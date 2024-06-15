/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:25:57 by camurill          #+#    #+#             */
/*   Updated: 2024/06/15 20:31:48 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **ag, char **env)
{
	ac = 0;
	ag = 0;
	int i = 0;

	char **split = ty_split(env, "\n")
	while (1)
	{
		printf("%s\n", split[i]);
		i++;
		if (split[i] = NULL)
			break ;
	}
	return (0);
}

