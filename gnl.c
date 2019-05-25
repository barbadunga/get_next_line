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

#include <stdio.h> // delete
#include <string.h> // delete
#include "get_next_line.h"

char	*ft_realloc(char **old_mem, size_t size)
{
	char	*new_mem;

	if (!(new_mem = ft_strnew(size)))
		return (NULL);
	if (*old_mem)
	{
		ft_memcpy(new_mem, *old_mem, ft_strlen(*old_mem));
		free(*old_mem);
		*old_mem = NULL;
	}
	return (new_mem);
}

int		cut_line(char **buf_str, size_t str_len, char **line)
{
	char	*tmp;

	if (!(*line = ft_strnew(str_len)))
		return (-1);
	*line = ft_strncpy(*line, *buf_str, str_len);
	str_len++;
	if (!(tmp = ft_strsub(*buf_str, str_len, ft_strlen(*buf_str + str_len))))
	{
		ft_strdel(buf_str);
		return (-1);
	}
	free(*buf_str);
	*buf_str = tmp;
	return (1);
}

int		check_line(char **str)
{
	char	*ptr;

	if (!*str)
		return (0);
	if ((ptr = ft_strchr(*str, '\n')))
		return (ptr - *str);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *tab[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			pos;
	int			sz;

	if (fd < 0 || fd > OPEN_MAX || !line || !*line || read(fd, buf, 0) < 0)
		return (-1);
	/*if ((pos = check_line(&tab[fd])))
	{
		if (!(cut_line(&tab[fd], pos, line)))
			return (sizeof(ft_strdel(&tab[fd])) - 1);
		return (1);
	}*/
	if ((pos = check_line(&tab[fd])))
		return (cut_line(&tab[fd], pos, line));
	while ((sz = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[sz] = '\0';
		tab[fd] = ft_realloc(&tab[fd], (tab[fd] ? ft_strlen(tab[fd]) + sz : 0));
		if (!(tab[fd] = ft_strjoin(tab[fd], buf)))
			return (sizeof(ft_strdel(&tab[fd])) - 1);
		if ((pos = check_line(&tab[fd])))
			return (cut_line(&tab[fd], pos, line));
	}
	return (0);
}

int main()
{
	int		fd1;
	int		fd2;
	char	*line;
	int 	val;

	line = "some string";
	fd1 = open("file", O_RDONLY);
	fd2 = open("file2", O_RDONLY);
	while ((val = get_next_line(fd1, &line)) > 0)
		printf("GNL[%d] : %s\n", val, line);
	printf("gnl_out = %d\n", val);
	/*val = get_next_line(fd1, &line);
	printf("GNL[%d] : %s\n", fd1, line);
	val = get_next_line(fd2, &line);
	printf("GNL[%d] : %s\n", fd2, line);
	val = get_next_line(fd1, &line);
	printf("GNL[%d] : %s\n", fd1, line);
	val = get_next_line(fd2, &line);
	printf("GNL[%d] : %s\n", fd2, line);
	val = get_next_line(fd2, &line);
	printf("GNL[%d] : %s\n", fd2, line);
	close(fd2); */
	close(fd1);
	return (0);
}