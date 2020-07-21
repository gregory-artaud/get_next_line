/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:02:22 by gregory           #+#    #+#             */
/*   Updated: 2020/07/21 23:11:57 by gregory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;
	int		flag;

	line = malloc(sizeof(char) * 1000);
	fd = open("test-files/test1.txt", O_RDONLY);
	flag = 1;
	line[0] = '\0';
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while (flag == 1)
	{
		ft_bzero(line, 1000);
		flag = get_next_line(fd, &line);
		printf("flag = %d : %s\n", flag, line);
	}
	return (EXIT_SUCCESS);
}
