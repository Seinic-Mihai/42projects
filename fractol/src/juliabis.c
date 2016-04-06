/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:35:30 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/02 18:05:49 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static unsigned	int		get_color(int iter)
{
	return (((125 - (int)(125 * cos((double)iter / 10.0))) << 16)
			+ ((125 + (int)(125 * sin((double)iter / 20.0))) << 8)
			+ (125 + (int)(125 * cos((double)iter / 30.0))));
}

static size_t	juliabis_iter(t_fract *fract, size_t maxiter)
{
	double	tmp;

	tmp = 0;
	fract->iter = 0;
	while (fract->iter < maxiter && (fract->z.r * fract->z.r + fract->z.i * fract->z.i) <= 4)
	{
		tmp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i *fract->z.i + fract->c.r;
		fract->z.i = 2* fract->z.i * tmp + fract->c.i;
		tmp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i *fract->z.i + fract->c.r;
		fract->z.i = 2* fract->z.i * tmp + fract->c.i;	
		fract->iter++;
	}
	return (fract->iter + fract->z.r - fract->z.i);
}

static void		create_juliabis(t_env *env)
{
	t_fract		fract;

	ft_bzero(&fract, sizeof(t_fract));
	while (fract.y < WIN_H)
	{
		fract.x = -1;
		while (++fract.x < WIN_W)
		{
			fract.c.r = (fract.x - (WIN_W + env->key.move_sides) *(env->key.zoom)) / (1.2 * env->key.zoom * WIN_W);
			fract.c.i = (fract.y - (WIN_H + env->key.move_updown) *(env->key.zoom)) / (1.2 * env->key.zoom * WIN_H);
			fract.z.r = fract.c.r;
			fract.z.i = fract.c.i;
			fract.c.r = env->key.x;
			fract.c.i = env->key.y;
			juliabis_iter(&fract, env->maxiter);
			if (fract.iter > 8 && fract.iter < env->maxiter)
				my_pixel_put_to_image(env, get_color(fract.iter), fract.x, fract.y);
			else if (fract.iter <= 8)	
				my_pixel_put_to_image(env, 0xffffff, fract.x, fract.y);
			else
				my_pixel_put_to_image(env, 0x000000, fract.x, fract.y);
		}
		fract.y++;
	}
}

void			draw_juliabis(t_env *env)
{
	create_juliabis(env);
}
