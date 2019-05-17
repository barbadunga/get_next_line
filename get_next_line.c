/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlexandrSergeev <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:24:16 by AlexandrSergeev   #+#    #+#             */
/*   Updated: 2019/05/14 10:24:16 by AlexandrSergeev  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_realloc(char **old, size_t size)
{
	char *new;

	if (!(new = ft_strnew(size)))
		return (NULL);
	if (*old)
	{
		ft_memcpy(new, *old, ft_strlen(*old));
		free(*old);
		*old = NULL;
	}
	return (new);
}

void	ft_clean(char **tab, char **ptr)
{
	char	*tmp;

	tmp = ft_strdup(*ptr);
	printf("dup : %s\n", tmp);
	free(*tab);
	*tab = NULL;
	*tab = ft_strdup(tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tab;
	char		buf[BUF_SIZE + 1];
	int			byte;
	char		*ptr;
	char		*tmp;

	if (fd < 0 || fd > 1023 || !line || !*line)
		return (-1);
	while ((byte = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[byte] = '\0';
		if (!(tab = ft_realloc(&tab, (!tab ? 0 : ft_strlen(tab)) + byte)))
		{
			ft_strdel(&tab);
			return (-1);
		}
		tab = ft_strcat(tab, buf);
		if ((ptr = ft_strchr(tab, '\n')))
		{
			printf("ptr %s\n", ptr);
			*line = ft_strnew(ptr - tab);
			*line = ft_strncpy(*line, tab, ptr - tab);
			return (1);
		}
	}
	return (1);
}

int main()
{
	int		fd;
	char	*line;

	line = "some string";
	fd = open("file", O_RDONLY);
	printf("GNL : %d\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	printf("GNL : %d\n", get_next_line(fd, &line));
	printf("line = %s\n", line);
	close(fd);
	return (0);
}