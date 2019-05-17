/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:44:38 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/18 14:44:38 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*ptr;

	ptr = s;
	if (!s || !f)
		return ;
	while (*ptr)
	{
		f(ptr - s, ptr);
		ptr++;
	}
}
