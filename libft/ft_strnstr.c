/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:13:57 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/09 23:13:57 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*p1;
	char	*p2;
	char	*match;

	p1 = (char*)s1;
	p2 = (char*)s2;
	if (!*p2)
		return (p1);
	while (*p1 && len)
	{
		if (*p1 != *p2)
			p1++;
		else
		{
			match = p1;
			while (*p2++ == *p1++ && len--)
				if (*p2 == '\0')
					return (match);
			p2 = (char*)s2;
			len += p1 - match;
			p1 = match + 1;
		}
		len--;
	}
	return (NULL);
}
