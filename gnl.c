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
	char	*new;

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

int		cut_line(char **str, char *pos, char **line)
{
	char	*tmp;

	tmp = ft_strdup(++pos);
	free(*str);
	*str = tmp;
}

int		get_next_line(const int fd, char **line)
{
	static char *tab[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		pos;
	int			sz;

	if (fd < 0 || fd > OPEN_MAX || !line || !*line || read(fd, buf, 0) < 0)
		return (-1);
	while ((sz = read(fd, buf, BUFF_SIZE)) < 0)
	{
		buf[sz] = '\0';

	}
}

int main()
{
	int		fd;
	char	*line;

	line = "some string";
	fd = open("file", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	close(fd);
	return (0);
}