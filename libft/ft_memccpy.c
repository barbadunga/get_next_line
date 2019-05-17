/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlexandrSergeev <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:53:02 by AlexandrSergeev   #+#    #+#             */
/*   Updated: 2019/04/08 17:53:02 by AlexandrSergeev  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst8;
	unsigned char *src8;

	dst8 = (unsigned char *)dst;
	src8 = (unsigned char *)src;
	while (n-- > 0)
	{
		if ((*dst8++ = *src8++) == (unsigned char)c)
			return (dst8);
	}
	return (NULL);
}
