/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:57:51 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/16 16:30:25 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*length;

	i = 0;
	j = 0;
	length = (char *)malloc((ft_strlen_gnl(s1) + \
				ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!length)
		return (0);
	while (s1[i])
	{
		length[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		length[i + j] = s2[j];
		j++;
	}
	length[i + j] = '\0';
	free (s1);
	return (length);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	if ((char)c == '\0')
		return (s + i);
	return (0);
}

char	*get_line(char *remainder)
{
	char	*line;
	int		i;

	i = 0;
	if (!remainder[0])
		return (0);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = malloc((sizeof(char) * i) + 2);
	if (!line)
		return (0);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
