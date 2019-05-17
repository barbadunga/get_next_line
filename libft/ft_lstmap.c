/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:57:07 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/25 13:57:07 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = f(lst);
	while ((lst = lst->next))
	{
		node = f(lst);
		ft_lstcat(&head, node);
	}
	return (head);
}
