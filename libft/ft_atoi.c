/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:50:39 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/09 21:50:39 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			num;
	int			sign;
	const char	*ptr;

	ptr = str;
	sign = 1;
	num = 0;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '+' && ft_isdigit(*(ptr + 1)))
		ptr++;
	if (*ptr == '-' && ft_isdigit(*(ptr + 1)))
	{
		sign = -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
		num = num * 10 + *ptr++ - '0';
	return (sign * num);
}
