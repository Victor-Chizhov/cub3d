/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:31:45 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/24 21:28:29 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*length;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	length = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!length)
		return ((void *)0);
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
	free((char *)s1);
	return (length);
}
