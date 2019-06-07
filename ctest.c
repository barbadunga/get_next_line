/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshagga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:00:29 by mshagga           #+#    #+#             */
/*   Updated: 2019/06/04 18:00:29 by mshagga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ver1.h"
#include <stdio.h>

int		read_line(int fd, char **b_str, t_vec **vec, char **n_pos)
{
	int		res;
	char	buff[BUFF_SIZE + 1];
	int		i;

	res = 1;
	if (!(*vec = ft_vec_init(BUFF_SIZE + 1, sizeof(char))))
		return (ERR);
	while (res > 0)
	{
		res = read(fd, buff, BUFF_SIZE);
		if (res)
		{
			buff[res] = '\0';
			i = 0;
			while (buff[i])
			{
				// *n_pos = (buff[i] == '\n') ? *n_pos + vec->total + i : *n_pos;
				ft_vec_add(vec, buff + i);
				if (buff[i++] == '\n')
					*n_pos = (*vec)->data + (*vec)->total;
			}
		}
		ft_vec_add(vec, "\0");
		*b_str = ft_strdup((*vec)->data);
		if (*n_pos)
			return (OK);
		// Need to cut *b_str by n_pos and then free vector
	}
	return (res);
}

int		cut_line(char **b_str, char **line, size_t s_len)
{
	char	*t_str;
	char	*n_pos;

	if (!(*line = ft_strnew(s_len)))
		return (ERR);
	n_pos = ft_strchr(*b_str, '\n');
	*line = ft_strncpy(*line, *b_str, n_pos++ - *b_str);
	if (!(t_str = ft_strsub(*b_str, n_pos - *b_str, ft_strlen(n_pos))))
		return (ERR);
	free(*b_str);
	*b_str = t_str;
	return (OK);
}

int		get_next_line(int fd, char **line)
{
	static char		*store[OPEN_MAX];
	t_vec			*vec;
	char			*n_pos;
	int				res;

	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (ERR);
	if (!store[fd] && !(store[fd] = ft_strnew(BUFF_SIZE)))
		return (ERR);
	n_pos = ft_strchr(store[fd], '\n'); // May pass empty store?
	res = !n_pos ? NO_LINE : OK;
	if (res == NO_LINE)
	{
		res = read_line(fd, &store[fd], &vec, &n_pos); // May pass empty store?
		ft_vec_add(&vec, "\0");
	}
	if (res > 0)
		res = cut_line(&store[fd], line, n_pos - store[fd]);
	if (!res && store[fd])
		*line = ft_strdup(store[fd]);
	if (!res || res == ERR)
		ft_vec_del(&vec);
	return (res);
}

int main()
{
	int fd;
	char	*line;
	int		gnl;

	fd = open("file2", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
		printf("GNL[%d] : %s [%zu]\n", gnl, line, ft_strlen(line));
	printf("GNL[%d] : %s [%zu]\n", gnl, line, ft_strlen(line));
	return (0);
}