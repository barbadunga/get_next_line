/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:06:52 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/14 17:06:52 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*p1;
	char	*p2;
	char	*match;

	p1 = (char*)s1;
	p2 = (char*)s2;
	if (!*p2)
		return (p1);
	while (*p1)
	{
		if (*p1 != *p2)
			p1++;
		else
		{
			match = p1;
			while (*p2++ == *p1++)
				if (*p2 == '\0')
					return (match);
			p2 = (char*)s2;
			p1 = match + 1;
		}
	}
	return (NULL);
}
