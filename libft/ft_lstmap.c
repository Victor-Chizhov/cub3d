/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:15:56 by vchizhov          #+#    #+#             */
/*   Updated: 2023/01/30 14:25:09 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*new;

	if (!lst || !f)
		return (0);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (0);
	a = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new->next)
		{
			ft_lstdelone(a, (*del));
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	return (a);
}
