/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:34:15 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/13 15:34:15 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst8;
	char	*src8;

	dst8 = (char*)dst;
	src8 = (char*)src;
	if (dst > src)
		while (len--)
			dst8[len] = src8[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
