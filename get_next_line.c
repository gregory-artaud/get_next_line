/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:34:27 by gregory           #+#    #+#             */
/*   Updated: 2020/10/23 16:34:00 by gregory          ###   ########lyon.fr   */
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
	while (!ft_end(remainder) && bytes_read)
	{
		if ((bytes_read = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[bytes_read] = 0;
		remainder = ft_strmcat(remainder, buf);
	}
	*line = ft_strdup(remainder);
	remainder = ft_remainder(remainder);
	free(buf);
	return (bytes_read != 0);
}
