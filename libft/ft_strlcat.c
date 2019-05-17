/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:51:56 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/14 14:51:56 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char *dst, const char *src, size_t len)
{
	char		*dst8;
	const char	*src8;

	dst8 = dst;
	src8 = src;
	while (len-- > 0)
		if (*src8)
			*dst8++ = *src8++;
	*dst8 = '\0';
	return (dst);
}

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	char	*ptr;
	size_t	len_dst;
	size_t	size_buf;

	size_buf = n;
	ptr = dst;
	while (*ptr && n > 0)
	{
		ptr++;
		n--;
	}
	if (n == 0)
		return (size_buf + ft_strlen(src));
	len_dst = size_buf - n;
	ft_copy(ptr, src, n - 1);
	return (len_dst + ft_strlen(src));
}
