/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:07:49 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/16 14:08:38 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_solution(char *solution, int j)
{
	int				i;

	i = 0;
	while (i < (j + 1) * j)
	{
		if ((i + 1) % (j + 1) == 0)
			solution[i] = '\n';
		else
			solution[i] = '.';
		++i;
	}
}

static char	*increasing_solution(char **tetris, char *sol, int width)
{
	free(sol);
	if ((sol = ft_strnew((width + 2) * (width + 1))) == NULL)
		return (NULL);
	init_solution(sol, width + 1);
	reset_all_tetris(tetris);
	return (sol);
}

static int	place_tetris(char *tetris, char *sol, int start, char letter)
{
	int		i;
	int		j;

	i = 0;
	while (!ft_isalpha(tetris[i]))
		++i;
	if (set_tetris(tetris, i, sol, start) == 4)
		return (1);
	reset_tetris(tetris);
	j = 0;
	while (sol[j])
	{
		if (sol[j] == letter)
			sol[j] = '.';
		++j;
	}
	return (0);
}

static int	fill_solution(char **tetris, char **sol, int index)
{
	int		i;
	char	*sol_cpy;

	i = 0;
	if (tetris[index] == NULL)
		return (1);
	sol_cpy = ft_strdup(*sol);
	while ((*sol)[i])
	{
		if (!place_tetris(tetris[index], *sol, i, 'A' + index))
		{
			i++;
			continue ;
		}
		if (fill_solution(tetris, sol, index + 1))
		{
			free(sol_cpy);
			return (1);
		}
		free(*sol);
		*sol = ft_strdup(sol_cpy);
	}
	free(sol_cpy);
	return (0);
}

char		*solver(char **tetris)
{
	int		i;
	int		j;
	char	*solution;

	i = 0;
	j = 0;
	while (tetris[i])
		++i;
	i *= 4;
	while (j * j < i)
		++j;
	if ((solution = ft_strnew((j + 1) * j)) == NULL)
		return (NULL);
	init_solution(solution, j);
	while (!fill_solution(tetris, &solution, 0))
	{
		if ((solution = increasing_solution(tetris, solution, j)) == NULL)
			return (NULL);
		++j;
	}
	return (solution);
}
