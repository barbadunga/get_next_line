/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:20:16 by mshagga           #+#    #+#             */
/*   Updated: 2019/06/12 19:40:10 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_vec_init(size_t size, int type)
{
	t_vec	*vec;

	if (!size || !(vec = (t_vec*)malloc(sizeof(t_vec))))
		return (NULL);
	vec->capacity = size;
	vec->total = 0;
	vec->type = type;
	if (!(vec->data = ft_memalloc(size * type)))
	{
		free(vec);
		return (NULL);
	}
	return (vec);
}
