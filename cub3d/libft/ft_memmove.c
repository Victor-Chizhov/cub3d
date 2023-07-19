/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:22:07 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/26 17:21:02 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	if (!dst && !src)
		return (dst);
	if (dst < src)
	{
		ft_memcpy(a, b, len);
	}
	else
	{
		while (len > 0)
		{
			a[len - 1] = b[len - 1];
			len--;
		}
	}
	return (dst);
}
