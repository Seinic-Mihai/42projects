/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:35:30 by mseinic           #+#    #+#             */
/*   Updated: 2016/03/29 20:19:54 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static unsigned	int		get_color(int iter)
{
	return (((125 - (int)(125 * cos((double)iter / 10.0))) << 16)
			+ ((125 + (int)(125 * sin((double)iter / 20.0))) << 8)
			+ (125 + (int)(125 * cos((double)iter / 30.0))));
}

static void				glynn_iter(t_fract *fract, size_t maxiter)
{
	double tmp;

	fract->iter = 0;
	while (fract->iter < maxiter && sqrt(fract->z.r * fract->z.r + fract->z.i * fract->z.i) < 1)
	{
		tmp = fract->z.r;
		fract->z.r = sqrt(fract->z.r * fract->z.r + fract->z.i * fract->z.i) + fract->c.r;
		fract->z.i = sqrt((2 * fract->z.i * tmp) * (2 * fract->z.i * tmp)) + fract->c.i;
		fract->iter++;
	}
}

static void				create_glynn(t_env *env)
{
	t_fract		fract;

	ft_bzero(&fract, sizeof(t_fract));
	while (fract.y < WIN_H)
	{
		fract.x = 0;
		while (fract.x < WIN_W)
		{
			fract.z.r = (fract.x - WIN_W / 2) /
						(1.2 * env->key.zoom * WIN_W) + env->key.move_sides;
			fract.z.i = (fract.y - WIN_H / 2) /
						(1.2 * env->key.zoom * WIN_H) + env->key.move_updown;
			fract.c.r = 0.291 + fract.c.r / 10;
			fract.c.i = 0.006 + (fract.c.i/ 100) / 4;
			glynn_iter(&fract, env->maxiter);
			if (fract.iter < env->maxiter)
				my_pixel_put_to_image(env, get_color(fract.z.r),
										fract.x, fract.y);
		//	else if (fract.z.r <= 5)
		//		my_pixel_put_to_image(env, 0xffffff, fract.x, fract.y);
			else
				my_pixel_put_to_image(env, 0x000000, fract.x, fract.y);
			fract.x++;
		}
		fract.y++;
	}
}

void					draw_glynn(t_env *env)
{
	create_glynn(env);
}
