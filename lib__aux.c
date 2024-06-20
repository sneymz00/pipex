/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib__aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:05:24 by camurill          #+#    #+#             */
/*   Updated: 2024/06/20 15:49:47 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	my_strcmp(char *cmp, char *src)
{
	size_t	i;

	i = 0;
	if (!cmp)
		return (1);
	while (cmp[i] || src[i])
	{
		if (cmp[i] != src[i])
			return ((unsigned char)(cmp[i]) - (unsigned char)(src[i]));
		i++;
	}
	return (0);
}

char	*my_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}
