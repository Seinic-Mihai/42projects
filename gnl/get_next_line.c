/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:21:03 by mseinic           #+#    #+#             */
/*   Updated: 2016/01/26 17:30:36 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		new_string_joined(char **stack, char *str)
{
	char	*tmp;

	tmp = ft_strdup(*stack);
	ft_strdel(&(*stack));
	*stack = ft_strjoin(tmp, str);
	ft_strdel(&tmp);
}

static int		reading_and_joining(char **str_rest, int *nb_bits,
								char **stack, int const fd)
{
	char	buff[BUFF_SIZE + 1];

	if (*str_rest == NULL)
	{
		*nb_bits = read(fd, buff, BUFF_SIZE);
		if (*nb_bits == -1)
		{
			ft_strdel(&(*stack));
			return (-1);
		}
		buff[*nb_bits] = '\0';
		new_string_joined(&(*stack), buff);
	}
	else
	{
		new_string_joined(&*(stack), *str_rest);
		ft_strdel(&(*str_rest));
	}
	return (0);
}

static int		return_line(char **str_rest, int const fd, char **line)
{
	int		nb_bits;
	char	*stack;
	char	*new_rest;

	nb_bits = 1;
	stack = ft_strdup("");
	while ((new_rest = ft_strchr(stack, '\n')) == NULL && nb_bits != 0)
		if (reading_and_joining(&(*str_rest), &nb_bits, &stack, fd) != 0)
			return (-1);
	if (new_rest != NULL)
	{
		new_rest[0] = '\0';
		*str_rest = ft_strdup(new_rest + 1);
	}
	*line = ft_strdup(stack);
	ft_strdel(&stack);
	if (nb_bits == 0 && *str_rest == '\0')
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char *rest_tab[257];

	if (fd < 0 || line == NULL)
		return (-1);
	return (return_line(&rest_tab[fd], fd, line));
}
