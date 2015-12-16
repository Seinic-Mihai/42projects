/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:47:52 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/15 12:28:15 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			tetrimons_init(char **tetriminos)
{
	int				i;

	i = -1;
	while (++i < 26)
		tetriminos[i] = NULL;
}

static char			**read_file(int fd)
{
	char			**tetriminos;
	char			buf[BUFF_SIZE];
	int				i;
	int				j;

	i = 0;
	j = 0;
	if ((tetriminos = (char **)malloc(sizeof(char *) * 27)) == NULL)
		return (NULL);
	tetrimons_init(tetriminos);
	ft_bzero(buf, BUFF_SIZE);
	if (read(fd, buf, BUFF_SIZE) < 0)
		return (NULL);
	if (ft_strlen(buf) < 20)
		return (NULL);
	while (buf[j] != '\0')
	{
		tetriminos[i] = ft_strsub(buf, 21 * i, 21);
		j += ft_strlen(tetriminos[i]);
		++i;
	}
	return (tetriminos);
}

static int			lex_tetriminos(char **tetriminos)
{
	int				i;

	while (*tetriminos != NULL)
	{
		i = 0;
		while ((*tetriminos)[i] != '\0')
		{
			if (((*tetriminos)[i] != '.' && (*tetriminos)[i] != '#')
					&& (((i + 1) % 5) == 0 && (*tetriminos)[i] != '\n'))
				return (0);
			++i;
		}
		++tetriminos;
	}
	return (1);
}

static int			parse_tetriminos(char **tetriminos)
{
	int			i;
	char		letter;

	letter = 'a';
	while (*tetriminos != NULL)
	{
		i = 0;
		while ((*tetriminos)[i] && (*tetriminos)[i] != '#')
			++i;
		if ((*tetriminos)[i] && is_tetriminos(*tetriminos, i, letter) != 4)
			return (0);
		++letter;
		++tetriminos;
	}
	return (1);
}

char				**check_file(int fd)
{
	char			**tetriminos;

	tetriminos = read_file(fd);
	if (!tetriminos)
		return (NULL);
	if (!lex_tetriminos(tetriminos))
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	if (!parse_tetriminos(tetriminos))
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	return (tetriminos);
}
