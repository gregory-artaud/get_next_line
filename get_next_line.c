/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:34:27 by gregory           #+#    #+#             */
/*   Updated: 2020/10/29 19:36:04 by gregory          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*remainder;
	int				bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	bytes_read = 1;
	while (ft_is_in(remainder, '\n') == -1 && bytes_read)
	{
		if ((bytes_read = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[bytes_read] = 0;
		remainder = ft_append(remainder, buf);
	}
	free(buf);
	*line = ft_strcdup(remainder, '\n');
	remainder = ft_remainder(remainder);
	return (bytes_read != 0);
}
