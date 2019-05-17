/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:34:39 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/25 12:34:39 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*ptr;

	if (!alst || !*alst || !del)
		return ;
	ptr = *alst;
	while (ptr)
	{
		temp = ptr->next;
		ft_lstdelone(&ptr, del);
		ptr = temp;
	}
	*alst = NULL;
}
