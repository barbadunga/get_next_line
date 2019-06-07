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
#include "ver1.h"

int		read_line(char **b_str, t_vec **vec, char *buff, int size)
{
	int		i;
	int		n_pos;

	n_pos = -1;
	i = 0;
	while (i != size)
	{
		if (n_pos < 0 && buff[i] == '\n')
			n_pos = (*vec)->total;
		ft_vec_add(vec, buff + i++);
	}
	if (n_pos != -1)
	{
		ft_vec_add(vec, "\0");
		*b_str = (*vec)->data;
	}
	return ((n_pos != -1 ? n_pos : NO_LINE));
}

int		init(int fd, t_vec **vec)
{
	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (ERR);
//	if (!*s_str && !(*s_str = ft_strnew(BUFF_SIZE + 1)))
//		return (ERR);
	if (!(*vec = ft_vec_init(BUFF_SIZE + 1, sizeof(char))))
		return (ERR);
	return (OK);
}

int		cut_line(char **b_str, char **line, size_t n_pos)
{
	char	*t_str;

	if (!(*line = ft_strnew(n_pos)))
		return (ERR);
	ft_memcpy(*line, *b_str, n_pos++);
	if (!(t_str = ft_strdup(*b_str + n_pos)))
		return (ERR);
	free(*b_str);
	*b_str = t_str;
	return (OK);
}

int		get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX];
	int			res;
	t_vec		*vec;
	char		buff[BUFF_SIZE + 1];
	char 		*n_pos;

	if ((res = init(fd, &vec)) == ERR)
		return (res);
	n_pos = !store[fd] ? NULL :ft_strchr(store[fd], '\n');
	res = !n_pos ? NO_LINE : OK;
	if (res == NO_LINE)
	{
		while (res == NO_LINE && (res = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[res] = '\0';
			res = read_line(&store[fd], &vec, buff, res);
			n_pos = (res != NO_LINE) ? store[fd] + res : NULL;
		}
	}
	if (n_pos)
		res = cut_line(&store[fd], line, n_pos - store[fd]);
	if (!res && store[fd])
	{
		*line = store[fd];
		return (OK);
	}
	if (res == ERR)
	{
		free(store[fd]);
		store[fd] = NULL;
	}
	return (res);
}

int main()
{
	char *line;
	int	fd;

	line = NULL;
	fd = open("file2", O_RDONLY);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	// free(*line);
	return (0);
}