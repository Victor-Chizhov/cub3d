/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:49:08 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/26 17:42:02 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	i = 0;
	if (!*n)
		return (h);
	while (h[i])
	{
		j = 0;
		while (h[i + j] && h[i + j] == n[j] && i + j < len)
		{
			j++;
			if (!n[j])
				return (h + i);
		}
		i++;
	}
	return (0);
}
