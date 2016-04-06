/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:05:26 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/02 14:57:56 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <window.h>
# define SQR(x) (x * x)
# define FR(x) (fract.x)

typedef struct	s_cmplx
{
	double		r;
	double		i;
}				t_cmplx;

typedef struct	s_fract
{
	t_cmplx		z;
	t_cmplx		c;
	int			x;
	int			y;
	double		rsquared;
	double		isquared;
	size_t		iter;
	size_t		maxiter;
}				t_fract;

void	draw_mandel(t_env *env);
void	draw_julia(t_env *env);
void	draw_newton(t_env *env);
void	draw_glynn(t_env *env);
void	draw_juliabis(t_env *env);
void	draw_moire(t_env *env);
void	draw_fuzzy(t_env *env);
int		list_fract(int ac, char **av);
void	create_fract(t_env *env, int fract);

#endif
