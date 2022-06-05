/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:28:42 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/19 15:06:04 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_buf(char *buf)
{
	free(buf);
	buf = NULL;
}

void	no_char_n(char **buf, char **line, char *fr)
{
	fr = *line;
	*line = ft_strjoin(*line, *buf);
	free(fr);
}

int	check_new_line(char **buf, char **line)
{
	char	*rf;
	char	*fr;
	char	*ptr_n;

	fr = NULL;
	if (!*buf)
		return (0);
	ptr_n = ft_strchr(*buf, '\n');
	if (ptr_n != NULL)
	{
		*ptr_n = '\0';
		fr = *line;
		*line = ft_strjoin(*line, *buf);
		free(fr);
		rf = *buf;
		*buf = ft_strdup(++ptr_n);
		free(rf);
		return (1);
	}
	else
	{
		no_char_n(buf, line, fr);
		return (0);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			readbytes;
	static char	*buf;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	*line = ft_strdup("");
	readbytes = 1;
	if ((check_new_line(&buf, line)))
		return (1);
	else
		free(buf);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	readbytes = read(fd, buf, BUFFER_SIZE);
	while (readbytes)
	{
		buf[readbytes] = '\0';
		if (check_new_line(&buf, line) != 0)
			return (1);
		readbytes = read(fd, buf, BUFFER_SIZE);
	}
	if (readbytes == 0)
		free_buf(buf);
	return (0);
}
