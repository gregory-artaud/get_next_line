/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:02:22 by gregory           #+#    #+#             */
/*   Updated: 2020/07/22 11:24:13 by gregory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		flag;
	char	*test_file;

	if (argc != 2)
		return (EXIT_FAILURE);
	test_file = ft_strjoin("test-files/", argv[1]);
	line = malloc(sizeof(char) * 1000);
	printf("\nOpening %s...\n", test_file);
	fd = open(test_file, O_RDONLY);
	flag = 1;
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while (flag == 1)
	{
		ft_bzero(line, 1000);
		printf("get_next_line call...\n");
		flag = get_next_line(fd, &line);
		printf("\treturn value = %d\n", flag);
		printf("\tline returned : %s\n", line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
