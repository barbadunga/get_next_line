/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:04:24 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/13 18:04:24 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*dst8;
	const char	*src8;

	dst8 = dst;
	src8 = src;
	while (len-- > 0)
	{
		if (*src8)
			*dst8++ = *src8++;
		else
			*dst8++ = '\0';
	}
	return (dst);
}
