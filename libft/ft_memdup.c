/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlexandrSergeev <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:05:06 by AlexandrSergeev   #+#    #+#             */
/*   Updated: 2019/04/27 15:05:06 by AlexandrSergeev  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	char	*new;
	char	*ptr;

	if (!(new = (char*)malloc(n)))
		return (NULL);
	ptr = (char*)src;
	while (n--)
		new[n] = ptr[n];
	return ((void*)new);
}
