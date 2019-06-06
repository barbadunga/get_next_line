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

int		read_line(int fd, char **b_str, char **line, t_vec **vec)
{
	int		i;
	char	buff[BUFF_SIZE + 1];
	int		res;

	i = 0;
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		while (buff[i] != '\n' && buff[i])
			ft_vec_add(vec, buff + i++);
		*line = (*vec)->data;
		free(vec);

	}
	return (NO_LINE);
}

int		check_line(char **b_str)
{
	char *ptr;

	ptr = ft_strchr(*b_str, '\n');
	if (!ptr)
		return (NO_LINE);
	return (ptr - *b_str);
}

int		get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX];
	int			res;
	t_vec		*vec;
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (ERR);
	if (!store[fd] && !(store[fd] = ft_strnew(BUFF_SIZE)))
		return (ERR);
	if (!(vec = ft_vec_init(BUFF_SIZE + 1, sizeof(char))))
		return (ERR);
	res = check_line(&store[fd]);
	if (res == NO_LINE)
		res = read_line(fd, &store[fd], line, &vec);
	return (res);
}

int main()
{
	char **line;
	int	fd;

	line = NULL;
	fd = open("file2", O_RDONLY);
	printf("%d\n", get_next_line(fd, line));
	return (0);
}