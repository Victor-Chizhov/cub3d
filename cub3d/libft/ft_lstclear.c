/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:37:28 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:48 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;
	t_list	*b;

	a = *lst;
	while (a)
	{
		b = a->next;
		ft_lstdelone(a, (*del));
		a = b;
	}
	*lst = 0;
}
