/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:20:36 by gregory           #+#    #+#             */
/*   Updated: 2020/10/29 15:42:55 by gregory          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char file[] = "test.txt";
	char *line;
	int res;

	fd = open(file, O_RDONLY);
	while ((res = get_next_line(fd, &line)))
		printf("%d : %s\n", res, line);
	printf("%d : %s\n", res, line);
	close(fd);
	return (0);
}
