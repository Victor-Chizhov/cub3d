/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:21:56 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/26 18:49:15 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_un(unsigned int nb, char *str, int size)
{
	if (nb > 9)
	{
		ft_putnbr_un(nb / 10, str, size - 1);
		nb = nb % 10;
	}
	str [size] = nb + '0';
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	numb;
	int				count;

	if (n < 0)
		numb = -1 * n;
	else
		numb = n;
	count = ft_len(numb);
	if (n < 0)
	{
		count++;
	}
	str = malloc(sizeof(char) * count + 1);
	if (n < 0)
	{
		str[0] = '-';
	}
	ft_putnbr_un(numb, str, count - 1);
	str[count] = '\0';
	return (str);
}
