/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregory <gregory@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:34:17 by gregory           #+#    #+#             */
/*   Updated: 2020/10/26 16:05:45 by gregory          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_remainder(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	if (!str[i])
		return (0);
	if (!(res = malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
		return (0);
	j = -1;
	while (str[i + ++j])
		res[j] = str[i + j];
	res[j] = 0;
	return (res);
}

int		ft_end(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_strndup(char *s, int n)
{
	char	*res;
	int		i;

	if (!(res = malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (s[i] && i < n)
		res[i] = s[i];
	res[i] = 0;
	return (res);
}

char	*ft_append(char *s1, char *s2)
{
	char	*res;
	int		res_ln;
	int		s1_ln;
	int		i;

	s1_ln = ft_strlen(s1);
	res_ln = s1_ln + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (res_ln + 1))))
		return (0);
	i = -1;
	while (++i < res_ln)
		if (i < s1_ln)
			res[i] = s1[i];
		else
			res[i] = s2[i - s1_ln];
	res[i] = 0;
	free(s1);
	return (res);
}
