/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:59:14 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/09 18:59:15 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first_elem;

	if (!lst || !f || ! del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		first_elem = ft_lstnew((*f)(lst->content));
		if (!first_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, first_elem);
		lst = lst->next;
	}
	return (new_list);
}
