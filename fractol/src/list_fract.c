/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:21:34 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/02 14:55:52 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		list_fract(int ac, char **av)
{
	int		fract;
	
	ac = 1;
	fract = 0;
	if (ft_strequ(ft_str_lower(av[1]), "julia"))
		fract = 2;
	else if (ft_strequ(ft_str_lower(av[1]), "mandelbrot"))
		fract = 3;
	else if (ft_strequ(ft_str_lower(av[1]), "newton"))
		fract = 4;
	else if (ft_strequ(ft_str_lower(av[1]), "glynn"))
		fract = 5;
	else if (ft_strequ(ft_str_lower(av[1]), "juliabis"))
		fract = 6;
	else if (ft_strequ(ft_str_lower(av[1]), "moire"))
		fract = 7;
	else if (ft_strequ(ft_str_lower(av[1]), "fuzzy"))
		fract = 8;
	return (fract);
}
