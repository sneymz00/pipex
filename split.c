/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:37:37 by camurill          #+#    #+#             */
/*   Updated: 2024/06/16 01:30:36 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_word(char const *text, char separate)
{
	bool	inside;
	int		count;

	count = 0;
	while (*text)
	{
		inside = false;
		while (*text == separate && *text)
			text++;
		while (*text != separate && *text)
		{
			if (!inside)
			{
				count++;
				inside = true;
			}
			text++;
		}
	}
	return (count);
}

static char	*ft_separated(const char *text, char s)
{
	static int	sep = 0;
	int			i;
	int			len;
	char		*final;

	i = 0;
	len = 0;
	while (text[sep] == s && text[sep])
		sep++;
	while ((text[sep + len] != s) && text[sep + len])
		len++;
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	while (text[sep] != s && text[sep])
		final[i++] = text[sep++];
	final[i] = '\0';
	return (final);
}

char **ty_split(const char *text, char separate)
{
	char	**split;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!text)
		return (NULL);
	size = count_word(text, separate);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	while (size-- >= 0)
		split[i++] = ft_separated(text, separate);
	split[i] = NULL;
	return (split);
}
/*
int main()
{
	int i = 0;
	char **split;
	char str[120] = "/home/camurill/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	split = ty_split(str, ':');
	while (1)
	{
		printf("%s\n", split[i]);
		i++;
		if (split[i] == NULL)
			break ;
	}
	return (0);
}*/
