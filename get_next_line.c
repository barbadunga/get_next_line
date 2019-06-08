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

#include "get_next_line.h"

int		read_line(int fd, char **b_str, t_vec **vec)
{
	int		i;
	int		size;
	int		pos;
	char	buff[BUFF_SIZE + 1];

	pos = NO_LINE;
	while (pos == NO_LINE && (size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		i = 0;
		while (i != size)
		{
			if (pos == NO_LINE && buff[i] == '\n')
				pos = (*vec)->total;
			ft_vec_add(vec, buff + i++);
		}
	}
	ft_vec_add(vec, "\0");
	*b_str = *b_str ? ft_strjoin(*b_str, (*vec)->data) : (*vec)->data;
	free(*vec);
	return (!size ? END : OK);
}

int		gnl_init(int fd, t_vec **vec)
{
	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (ERR);
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
	char		*n_pos;

	if ((res = gnl_init(fd, &vec)) == ERR)
		return (res);
	n_pos = !store[fd] ? NULL : ft_strchr(store[fd], '\n');
	res = !n_pos ? NO_LINE : OK;
	if (res == NO_LINE)
		res = read_line(fd, &store[fd], &vec);
	n_pos = ft_strchr(store[fd], '\n');
	if (n_pos)
		res = cut_line(&store[fd], line, n_pos - store[fd]);
	if (!res && *store[fd])
	{
		*line = ft_strdup(store[fd]);
		ft_strdel(&store[fd]);
		return (OK);
	}
	if (res == ERR)
		ft_strdel(&store[fd]);
	return (res);
}
