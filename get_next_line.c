/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:44:05 by gregory           #+#    #+#             */
/*   Updated: 2020/07/21 23:39:25 by gregory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** This function unloads bf at the back of s
** until the bf is empty or '\n' is encountered.
** It return 0 if no '\n' is encountered, 1 otherwise.
*/
int		unload_buffer(char *bf, char *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	i = 0;
	while ((bf[i] == '\n') && (i < BUFFER_SIZE))
		i++;
	j = i;
	while ((bf[j] != '\n') && (j < BUFFER_SIZE))
		j++;
	tmp = ft_strndup((bf + i), (j - i));
	ft_memset((bf + i), '\n', (j - i));
	ft_strlcat(s, tmp, ft_strlen(s) + ft_strlen(tmp) + 1);
	free(tmp);
	if (j == BUFFER_SIZE)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char buffer[BUFFER_SIZE] = {'\n'};
	int			end_of_line;
	int			bytes_read;
	
	bytes_read = BUFFER_SIZE;
	end_of_line = unload_buffer(buffer, *line);
	while (!end_of_line && (bytes_read == BUFFER_SIZE))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("\n===BUFFER===\n");
		for (int i = 0; i < BUFFER_SIZE; i++)
			printf("%c", buffer[i]);
		printf("\n");
		end_of_line = unload_buffer(buffer, *line);
	}
	if (end_of_line)
		return (1);
	if ((bytes_read <= BUFFER_SIZE) && (bytes_read != -1))
		return (0);
	return (-1);
}
