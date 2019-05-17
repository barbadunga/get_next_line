/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlexandrSergeev <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:37:28 by AlexandrSergeev   #+#    #+#             */
/*   Updated: 2019/04/08 11:37:28 by AlexandrSergeev  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst8;
	unsigned char	*src8;

	dst8 = (unsigned char*)dst;
	src8 = (unsigned char*)src;
	while (n-- > 0)
		*dst8++ = *src8++;
	return (dst);
}
