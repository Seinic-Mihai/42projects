/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:47:56 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/16 18:10:04 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			reset_tetris(char *tetris)
{
	int			i;

	i = 0;
	while (tetris[i])
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
			tetris[i] += 32;
		++i;
	}
}

void			reset_all_tetris(char **tetris)
{
	int			i;

	i = 0;
	while (tetris[i])
	{
		reset_tetris(tetris[i]);
		++i;
	}
}

int				is_correct_tetris(char *tetris, int i, char letter)
{
	int			nb_hash;

	nb_hash = 0;
	if (i >= 0 && i < 20 && tetris[i] == '#')
	{
		tetris[i] = letter;
		++nb_hash;
		nb_hash += is_correct_tetris(tetris, i + 1, letter);
		nb_hash += is_correct_tetris(tetris, i + 5, letter);
		nb_hash += is_correct_tetris(tetris, i - 1, letter);
		nb_hash += is_correct_tetris(tetris, i - 5, letter);
	}
	return (nb_hash);
}

int				set_tetris(char *tetris, int i, char *solution, int j)
{
	int			nb_hash;
	int			len;

	nb_hash = 0;
	len = 0;
	while (solution[len] != '\n')
		++len;
	++len;
	if (i >= 0 && i < 20 && j >= 0 && j < (len * (len - 1))
			&& tetris[i] >= 'a' && solution[j] == '.')
	{
		tetris[i] -= 32;
		solution[j] = tetris[i];
		++nb_hash;
		nb_hash += set_tetris(tetris, i + 1, solution, j + 1);
		nb_hash += set_tetris(tetris, i + 5, solution, j + len);
		nb_hash += set_tetris(tetris, i - 1, solution, j - 1);
	}
	return (nb_hash);
}
