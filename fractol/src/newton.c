/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 12:23:55 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/06 10:38:58 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static unsigned	int		get_color(int iter)
{
	return (((125 - (int)(125 * cos((double)iter / 10.0))) << 16)
			+ ((125 + (int)(125 * sin((double)iter / 20.0))) << 8)
			+ (125 + (int)(125 * cos((double)iter / 30.0))));
}

static void				newton_iter(t_fract *fract, size_t maxiter)
{
	double tmp;
	double zzr;
	double zzi;
	double d;

	fract->iter = 0;
	while (fract->iter < maxiter)
	{
		tmp = fract->z.r;
		zzr = fract->z.r * fract->z.r;
		zzi = fract->z.i * fract->z.i;
		d = 3.0 * ((zzr - zzi) * (zzr - zzi) + 4.0 * (zzr * zzi));
		if (d == 0)
			d = 0.000001;
		fract->z.r = (2.0 / 3.0) * fract->z.r + (zzr - zzi) / d + fract->c.r;
		fract->z.i = (2.0 / 3.0) * fract->z.i - 2.0 *
					tmp * fract->z.i / d + fract->c.i;
		fract->iter++;
	}
}

static void				create_newton(t_env *env)
{
	t_fract		fract;

	ft_bzero(&fract, sizeof(t_fract));
	while (fract.y < WIN_H)
	{
		fract.x = 0;
		while (fract.x < WIN_W)
		{
			fract.z.r = (fract.x - (WIN_W + env->key.move_sides)/ 2) /
						(1.2 * env->key.zoom * WIN_W);
			fract.z.i = (fract.y - (WIN_H + env->key.move_updown)/ 2) /
						(1.2 * env->key.zoom * WIN_H);
			newton_iter(&fract, env->maxiter);
			if (fract.z.r > 0)
				my_pixel_put_to_image(env, get_color(fract.z.r),
										fract.x, fract.y);
			else if (fract.z.r <= 0.3 && fract.z.i > 0.0)
				my_pixel_put_to_image(env, get_color(fract.z.r - fract.iter), fract.x, fract.y);
			else
				my_pixel_put_to_image(env, get_color(fract.z.r + fract.iter), fract.x, fract.y);
			fract.x++;
		}
		fract.y++;
	}
}

void					draw_newton(t_env *env)
{
	create_newton(env);
}
