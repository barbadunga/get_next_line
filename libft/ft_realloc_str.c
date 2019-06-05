/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:40:40 by mshagga           #+#    #+#             */
/*   Updated: 2019/06/05 12:40:40 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_str(char **s_old, size_t len)
{
	char	*s_new;

	if (!(s_new = ft_strnew(len)))
		return (NULL);
	if (*s_old)
	{
		ft_strcpy(s_new, *s_old);
		ft_strdel(s_old);
	}
	return (s_new);
}
