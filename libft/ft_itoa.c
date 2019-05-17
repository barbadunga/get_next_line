/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:48:20 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/23 20:48:20 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nlen(int n)
{
	int size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char			*s_num;
	int				del;
	unsigned int	num;

	del = (n < 0 ? ft_nlen(n) + 1 : ft_nlen(n));
	num = (n < 0 ? (unsigned int)-n : (unsigned int)n);
	if (!(s_num = ft_strnew(del)))
		return (NULL);
	(n < 0 ? s_num[0] = '-' : 0);
	if (!num)
	{
		s_num[0] = '0';
		return (s_num);
	}
	while (num)
	{
		s_num[--del] = num % 10 + '0';
		num /= 10;
	}
	return (s_num);
}
