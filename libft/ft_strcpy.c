/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:53:52 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/13 17:53:52 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char		*dst8;
	const char	*src8;

	dst8 = dst;
	src8 = src;
	while ((*dst8++ = *src8++) != '\0')
		;
	return (dst);
}
