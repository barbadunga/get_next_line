/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:51:30 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/18 17:51:30 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	if (!(j = ft_strlen(s)))
		return (!(str = ft_strnew(0)) ? NULL : str);
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[--j] == '\n' || s[j] == ' ' || s[j] == '\t')
		;
	if (i < j)
	{
		if (!(str = ft_strnew(j - i + 1)))
			return (NULL);
		return (ft_strncpy(str, s + i, j - i + 1));
	}
	return (!(str = ft_strnew(0)) ? NULL : str);
}
