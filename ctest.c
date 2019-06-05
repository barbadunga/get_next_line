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

#include "get_next_line.h"
#include <stdio.h>

int		read_line(int fd, char **b_str, t_vec **v, char **line, char **n_pos)
{
	int		res;
	t_vec	*vec;
	char	buff[BUFF_SIZE + 1];
	int		i;

	res = 1;
	vec = *v;
	while (res > 0)
	{
		res = read(fd, buff, BUFF_SIZE);
		if (res)
		{
			buff[res] = '\0';
			i = 0;
			while (buff[i])
			{
				*n_pos = (buff[i] == '\n') ? *n_pos + vec->total + i : *n_pos;
				ft_vec_add(&vec, buff + i);
			}
		}
		*b_str = ft_memcpy(*b_str, vec->data, vec->total * vec->type);
		// Need to cut *b_str by n_pos and then free vector
	}

	return (res);
}

int		cut_line(char **b_str, char **line, size_t s_len)
{
	char	*t_str;

	if (!(*line = ft_strnew(s_len)))
		return (ERR);
	*line = ft_strncpy(*line, *b_str, s_len++);
	if (!(t_str = ft_strsub(*b_str, s_len, ft_strlen(*b_str + s_len))))
		return (ERR);
	free(*b_str);
	*b_str = t_str;
	return (OK);
}

int		get_next_line(int fd, char **line)
{
	char	*store[OPEN_MAX];
	t_vec	*vec;
	char	*n_pos;
	int		res;

	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (-1);
	// Allocate memory for store
	if (!(vec = ft_vec_init(BUFF_SIZE, sizeof(char))))
		return (ERR);
	n_pos = (ft_strchr(store[fd], '\n')); // May pass empty store?
	res = !n_pos ? NO_LINE : OK;
	if (res == NO_LINE)
		res = read_line(fd, &store[fd], &vec,line, &n_pos); // May pass empty store?
	res = cut_line(&store[fd], line, n_pos - store[fd]); // Pass not pointer, but int
	return (1);
}

int main()
{
	int fd;

	fd = open("libft/ft_strnew.c", O_RDONLY);
	printf("%d\n", get_next_line(fd, NULL));
	return (0);
}