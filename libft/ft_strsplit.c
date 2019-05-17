/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:24:03 by mshagga           #+#    #+#             */
/*   Updated: 2019/04/19 18:24:03 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	const char	*ptr;
	int			size;

	size = 0;
	ptr = str;
	while (*ptr)
	{
		size++;
		if (!(ptr = ft_strchr(ptr, c)))
			return (size);
		while (*ptr == c)
			ptr++;
	}
	return (size);
}

static char	*ft_skip(const char *str, char c)
{
	while (*str == c)
		str++;
	return ((char*)str);
}

static char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*end;
	char	*start;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	end = ft_skip(s, c);
	if (!(tab = (char**)ft_memalloc(8 * (word_count(s, c) + 1))))
		return (NULL);
	while (*end)
	{
		start = end;
		if (!(end = ft_strchr(start, c)))
			end = (char*)s + ft_strlen(s);
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char) * (end - start + 1))))
			return (ft_free(tab));
		ft_strncat(tab[i++], start, end - start);
		end = ft_skip(end, c);
	}
	return (tab);
}
