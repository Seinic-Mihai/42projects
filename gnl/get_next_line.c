/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:21:03 by mseinic           #+#    #+#             */
/*   Updated: 2016/01/08 20:22:28 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_ret()
{
	int		go;

	go = 1;
	while (read(fd, buff, BUFF_SIZE) > 0 && go == 1)
	{

		go = 1;
	}
}

int get_next_line(int const fd, char **line)
{
	static t_data	*stock;

	if (line == NULL)
		return (-1);
}
