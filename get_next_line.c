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

char	*ft_do(char **old_mem, char *join, size_t size)
{
	char	*new_mem;

	if (!(new_mem = (char*)malloc(size + 1)))
		return (NULL);
	new_mem[size + 1] = '\0';
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

int		read_line(int fd, char **b_str, char **line)
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
			s_len = *b_str ? ft_strlen(*b_str) : 0;
			*b_str = ft_realloc(b_str, s_len + res);
			*b_str = ft_strcat(*b_str, buff);
			if (ft_strchr(*b_str, '\n'))
				return (OK);
		}
	}
	if (*b_str)
	{
		*line = ft_strdup(*b_str);
		res = 1;
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char	*store[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			res;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buf, 0) < 0) // !line || !*line ||
			return (-1);
	res = get_line(&store[fd], line);
	if (res == OK)
		return (OK);
	if (res == NO_LINE)
	{
		res = read_line(fd, &store[fd], line);
		res = res > 0 && *line ? get_line(&store[fd], line) : res;
	}
	if (!res)
		ft_strdel(&store[fd]);
	return (res);
}

/* int main()
{
	char	*line;
	int		fd;
	int		gnl;

	fd = open("tests/01_test.txt", O_RDONLY);
	if (!(line = (char*)malloc(1)))
		return (0);
	while ((gnl = get_next_line(fd, &line)) == 1)
		printf("GNL[%d] : %s\n", gnl, line);
	printf("GNL[%d] : %s\n", gnl, line);
	return (0);
} */