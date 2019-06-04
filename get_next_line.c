/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AlexandrSergeev <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:57:38 by AlexandrSergeev   #+#    #+#             */
/*   Updated: 2019/05/27 15:57:38 by AlexandrSergeev  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 1. Need to check on valgrind
 * 2. Remake logic
*/

#include "get_next_line.h"
#include <stdio.h>

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

int		get_line(char **s_str, char **line)
{
	size_t	s_len;
	char	*t_str;
	char	*n_pos;

	if (!*s_str)
		return(NO_LINE);
	n_pos = ft_strchr(*s_str, '\n');
	s_len = n_pos ? n_pos - *s_str : 0;
	if (!n_pos)
		return (NO_LINE);
	if (!(*line = ft_strnew(s_len)))
		return (ERR);
	*line = ft_strncpy(*line, *s_str, s_len++);
	if (!(t_str = ft_strsub(*s_str, s_len, ft_strlen(n_pos))))
		return (ERR);
	free(*s_str);
	*s_str = t_str;
	return (OK);
}

int		read_line(int fd, char **s_str, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		res;
	size_t	s_len;

	res = 1;
	while (res >  0)
	{
		if ((res = read(fd, buff, BUFF_SIZE)) < 0)
			return (ERR);
		if (res)
		{
			buff[res] = '\0';
			s_len = *s_str ? ft_strlen(*s_str) : 0;
			*s_str = ft_realloc(s_str, s_len + res);
			*s_str = ft_strcat(*s_str, buff);
			if (ft_strchr(*s_str, '\n'))
				return (OK);
		}
	}
	if (*s_str)
		*line = ft_strdup(*s_str);
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char	*store[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			res;

	if (fd < 0 || fd > OPEN_MAX || !line || !*line || read(fd, buf, 0) < 0)
			return (-1);
	res = get_line(&store[fd], line);
	if (res == OK)
		return (OK);
	if (res == NO_LINE)
	{
		res = read_line(fd, &store[fd], line);
		res = res > 0 ? get_line(&store[fd], line) : res;
	}
	if (!res)
		ft_strdel(&store[fd]);
	return (res);
}