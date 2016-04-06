/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:35:30 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/02 14:50:09 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static unsigned	int		get_color(int iter)
{
	return (((125 - (int)(125 * cos((double)iter / 5.0))) << 16)
			+ ((125 + (int)(125 * sin((double)iter / 10.0))) << 8)
			+ (125 + (int)(125 * cos((double)iter / 15.0))));
}

static size_t	moire_iter(t_fract *fract, size_t maxiter)
{
	double	tmp;

	tmp = 0;
	fract->iter = 0;
	while (fract->iter < maxiter && (sqrt(fract->z.r * fract->z.r + fract->z.i * fract->z.i)) < 10)
	{
		tmp = fract->z.r;
		fract->z.r = fract->z.r * fract->z.r - fract->z.i *fract->z.i;
		fract->z.i = 2* fract->z.i * tmp;
		fract->z.r = (fract->z.r * fract->z.r) + fract->c.r;
		fract->z.i = sqrt(fract->z.i * fract->z.i) * 2 - fract->c.i;
		fract->iter++;
	}
	return (fract->iter);
}

static void		create_moire(t_env *env)
{
	t_fract		fract;

	ft_bzero(&fract, sizeof(t_fract));
	while (fract.y < WIN_H)
	{
		fract.x = -1;
		while (++fract.x < WIN_W)
		{
			fract.z.r = (fract.x - (WIN_W + env->key.move_sides) * 0.5) / (1.2 * env->key.zoom * WIN_W);
			fract.z.i = (fract.y - (WIN_H + env->key.move_updown) * 0.5) / (1.2 * env->key.zoom * WIN_H);
			fract.c.r = -0.375;
			fract.c.i = 0.002;
			moire_iter(&fract, env->maxiter);
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

void			draw_moire(t_env *env)
{
	create_moire(env);
}
