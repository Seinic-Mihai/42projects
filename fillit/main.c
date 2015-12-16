/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:49:09 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/16 12:43:50 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_exit(void)
{
	ft_putendl("error");
	exit(2);
}

int					main(int ac, char **av)
{
	int				fd;
	char			**tetris;
	char			*solution;

	if (ac != 2)
		ft_exit();
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit();
	tetris = check_file(fd);
	close(fd);
	if (tetris == NULL)
		ft_exit();
	solution = solver(tetris);
	if (solution == NULL)
		ft_exit();
	ft_putstr(solution);
	clear_tab(tetris);
	free(solution);
	return (0);
}
