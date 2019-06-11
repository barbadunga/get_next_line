/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlexandrSergeev <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:24:16 by AlexandrSergeev   #+#    #+#             */
/*   Updated: 2019/06/10 17:31:17 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int		read_line(int fd, char **b_str, t_vec **vec)
//{
//	int		i;
//	int		size;
//	int		pos;
//	char	buff[BUFF_SIZE + 1];
//	char	*tmp;
//
//	pos = NO_LINE;
//	while (pos == NO_LINE && (size = read(fd, buff, BUFF_SIZE)) > 0)
//	{
//		buff[size] = '\0';
//		i = 0;
//		while (i != size)
//		{
//			if (pos == NO_LINE && buff[i] == '\n')
//				pos = (*vec)->total;
//			ft_vec_add(vec, buff + i++);
//		}
//	}
//	if ((*vec)->total > 0)
//	{
//		ft_vec_add(vec, "\0");
//		tmp = *b_str;
//		(*vec) = (*vec)->capacity > (*vec)->total ? ft_vec_resize(vec) : (*vec);
//		*b_str = *b_str ? ft_strjoin(*b_str, (*vec)->data) :
//				 ft_strdup((*vec)->data);
//		ft_strdel(&tmp);
//	}
//	return (!size ? END : OK);
//}

int		bufferize(t_vec **vec, char **b_str)
{
	char	*tmp;

	ft_vec_add(vec, "\0");
	tmp = *b_str;
	if ((*vec)->capacity > (*vec)->total)
		(*vec) = ft_vec_resize(vec);
	if (*b_str)
		*b_str = ft_strjoin(*b_str, (*vec)->data);
	else
		*b_str = ft_strdup((*vec)->data);
	if (!(*b_str))
		return (ERR);
	ft_strdel(&tmp);
	return (OK);
}

int		read_line(int fd, char **b_str, t_vec **vec)
{
	int		i;
	int		ret;
	int		pos;
	char	buff[BUFF_SIZE + 1];
	int		res;

	pos = NO_LINE;
	while (pos == NO_LINE && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		i = 0;
		while (i != ret)
		{
			if (pos == NO_LINE && buff[i] == '\n')
				pos = (*vec)->total;
			ft_vec_add(vec, buff + i++);
		}
	}
	if ((*vec)->total > 0)
		res = bufferize(vec, b_str);
	ret = !ret ? END : OK;
	return ( res != ERR ? ret : res);
}

int		gnl_init(int fd, t_vec **vec)
{
	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (ERR);
	if (!(*vec = ft_vec_init(BUFF_SIZE, sizeof(char))))
	{
		free(*vec);
		return (ERR);
	}
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
	n_pos = !store[fd] ? NULL : ft_strchr(store[fd], '\n');
	n_pos = n_pos;
	if (n_pos)
		res = cut_line(&store[fd], line, n_pos - store[fd]);
	if (!res && store[fd] && *store[fd])
	{
		*line = ft_strdup(store[fd]);
		ft_strdel(&store[fd]);
		return (OK);
	}
	if (!res || res == ERR)
		ft_strdel(&store[fd]);
	return (res);
}
