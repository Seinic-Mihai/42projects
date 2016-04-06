/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:35:30 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/06 14:33:20 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static unsigned	int		get_color(int iter)
{
	return (((125 - (int)(125 * cos((double)iter / 70.0))) << 16)
			+ ((125 + (int)(125 * sin((double)iter / 50.0))) << 8)
			+ (125 + (int)(125 * cos((double)iter / 30.0))));
}

static void		create_mandel(t_env *env)
{
	t_fract		fract;
	double		tmp;	

	ft_bzero(&fract, sizeof(t_fract));
	while (fract.y < WIN_H)
	{
		fract.x = 0;
		while (fract.x < WIN_W)
		{
			fract.c.r = (fract.x - WIN_W * 0.5) * RATIO / (env->key.zoom * WIN_W) + env->key.move_sides;
			fract.c.i = (fract.y - WIN_H * 0.5) / (env->key.zoom * WIN_H) + env->key.move_updown;
			fract.z.r = 0;
			fract.z.i = 0;
			fract.iter = 0;
			while (fract.iter < env->maxiter && (fract.z.r * fract.z.r + fract.z.i * fract.z.i) <= 4)
			{
				tmp = fract.z.r;
				fract.z.r = fract.z.r * fract.z.r - fract.z.i *fract.z.i + fract.c.r;
				fract.z.i = 2* fract.z.i * tmp + fract.c.i;
				fract.iter++;
			}
			if (fract.iter >= 0 && fract.iter < env->maxiter)
				my_pixel_put_to_image(env, get_color(fract.iter), fract.x, fract.y);
			//else if (fract.iter <= 8)	
			//	my_pixel_put_to_image(env, 0xffffff, fract.x, fract.y);
			else
				my_pixel_put_to_image(env, 0x000000, fract.x, fract.y);
			fract.x++;
		}
		fract.y++;
	}

}

void			draw_mandel(t_env *env)
{
	create_mandel(env);
}
