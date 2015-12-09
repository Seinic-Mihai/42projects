/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:49:09 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/09 14:32:19 by mseinic          ###   ########.fr       */
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
	char			**tetriminos;
	char			*solution;

	if (ac != 2)
		ft_exit();
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit();
	tetriminos = check_file(fd);
	close(fd);
	if (tetriminos == NULL)
		ft_exit();
	if ((solution = solver(tetriminos)) == NULL)
		ft_exit();
	ft_putendl(solution);
	ft_clear_tab(tetriminos);
	free(solution);
	return (0);
}
