/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:45:31 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/13 17:45:31 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *new;

	if (!(new = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
