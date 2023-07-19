/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:37:31 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/29 16:05:51 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = malloc(count * size);
	if (!s1)
	{
		return (0);
	}
	while (i < count * size)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
