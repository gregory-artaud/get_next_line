/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:44:05 by gregory           #+#    #+#             */
/*   Updated: 2020/07/22 12:20:47 by gregory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** This function unloads bf at the back of s
** until the bf is empty or '\n' is encountered.
** It returns :
** -> 1 if '\n is encountered,
** -> 0 otherwise.
*/
int		unload_buffer(char *bf, char *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;
	int				res;

	res = 0;
	i = 0;
	while (((bf[i] == '\n') || (bf[i] == 10)) && (i < BUFFER_SIZE))
		i++;
	j = i;
	while ((bf[j] != '\n') && (j < BUFFER_SIZE))
		j++;
	if (j < BUFFER_SIZE)
	{
		if (bf[j] == '\n')
			res = 1;
	}
	tmp = ft_strndup((bf + i), (j - i));
	ft_memset((bf + i), '\n', (j - i));
	ft_strlcat(s, tmp, ft_strlen(s) + ft_strlen(tmp) + 1);
	free(tmp);
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char buffer[BUFFER_SIZE] = {'\n'};
	int			end;
	int			bytes_read;
	
	bytes_read = BUFFER_SIZE;
	end = unload_buffer(buffer, *line);
	while (!end)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		/*printf("\n===BUFFER===\n");
		for (int i = 0; i < BUFFER_SIZE; i++)
			printf("%d ", buffer[i]);
		printf("\n");*/
		end = unload_buffer(buffer, *line);
		if (bytes_read < BUFFER_SIZE)
			end = -1;
	}
	//printf("\n===BYTES_READ===\nbytes_read = %d\n", bytes_read);
	if (end == -1)
		return (0);
	if (end == 1)
		return (1);
	return (-1);
}
