/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:54:13 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:54:14 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*second;

	if (!lst && !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		second = ft_lstnew(f(lst->content));
		if (!second)
		{
			ft_lstclear(&second, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&first, second);
	}
	return (first);
}
