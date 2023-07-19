/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:12:47 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/29 15:36:07 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	str = (char *)s;
	i = ft_strlen(str);
	if (!str)
		return (0);
	while (str[j])
		j++;
	while (i >= 0)
	{
		if (str[j] == (char)c)
			return (str + j);
		i--;
		j--;
	}
	return (0);
}
