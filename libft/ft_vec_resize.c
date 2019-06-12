/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:52:52 by mshagga           #+#    #+#             */
/*   Updated: 2019/06/12 19:40:03 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_vec_resize(t_vec **vec)
{
	void	*data;

	data = (*vec)->data;
	if (!((*vec)->data = ft_memalloc((*vec)->total * (*vec)->type)))
		return (NULL);
	(*vec)->data = ft_memcpy((*vec)->data, data, (*vec)->total * (*vec)->type);
	(*vec)->capacity = (*vec)->total;
	free(data);
	return (*vec);
}
