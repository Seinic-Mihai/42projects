/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:21:03 by mseinic           #+#    #+#             */
/*   Updated: 2016/01/13 16:00:15 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int		return_the_line(char **str, char *divide, char **line)
{
	char *next_line;

	next_line = NULL;
	if (ft_strequ(*str, "\n") == 1)
		*line = ft_strdup("");
	else if (divide == NULL)
		*line = ft_strdup(*str);
	else if (divide != NULL)
	{
		divide[0] = '\0';
		*line = ft_strdup(*str);
		if (divide[1] != '\0')
			next_line = ft_strdup(&divide[1]);
	}
	ft_strdel(str);
	if (next_line != NULL)
		*str = next_line;
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static	char	*str;
	char			buff[BUFF_SIZE + 1];
	char			*next_line;
	char			*divide;

	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0
			&&	(divide = ft_strchr(str, '\n')) == NULL)
	{
		next_line = ft_strjoin(str, buff);
		if (str != NULL)
			ft_strdel(&str);
		str = next_line;
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && str != NULL)
		return (0);
	return (return_the_line(&str, divide, line));
}
