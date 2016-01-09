/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:21:03 by mseinic           #+#    #+#             */
/*   Updated: 2016/01/09 17:19:16 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_ret(int const fd, char *line)
{
	int		exit;
	char	buff[BUFF_SIZE + 1];
	int 	i;

	go = 1;
	while (read(fd, buff, BUFF_SIZE) > 0 && exit == 1)
	{
		i = 0;
		while (i < BUFF_SIZE && buff[i] != '\n')
		{
			i++;
			exit = 0;
		}
		buff[i] = '\0';
		ft_strjoin(*line, buff);
	}
	i++;
	if (i == BUFF_SIZE)
		return (1);
	else
	{
		(stock[fd])->data = ft_strdup(buff + i);
	}
}

int get_next_line(int const fd, char **line)
{
	static t_data	stock[100];

	if (line == NULL)
		return (-1);
}
