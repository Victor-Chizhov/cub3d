/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:50:18 by vchizhov          #+#    #+#             */
/*   Updated: 2023/02/20 17:09:45 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_remainder(char *remainder)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (0);
	}
	str = malloc(ft_strlen_gnl(remainder) - i + 1);
	if (!str)
		return (0);
	i++;
	while (remainder[i])
	{
		str[j++] = remainder[i++];
	}
	str[j] = '\0';
	free (remainder);
	return (str);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			byte_size;
	static char	*remainder;

	byte_size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (!ft_strchr_gnl(remainder, '\n') && byte_size != 0)
	{
		byte_size = read(fd, buf, BUFFER_SIZE);
		if (byte_size == -1)
			return (0);
		buf[byte_size] = '\0';
		if (!remainder)
		{
			remainder = (char *)malloc(1 * sizeof(char));
			remainder[0] = '\0';
		}
		remainder = ft_strjoin_gnl(remainder, buf);
	}
	line = get_line(remainder);
	remainder = next_remainder(remainder);
	return (line);
}
