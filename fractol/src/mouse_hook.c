/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:40:19 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/06 14:34:13 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <fractol.h>
#include <stdio.h> //

int		def_mouse_hook(int button, int x, int y, void *param)
{
	t_env *const env = param;
	printf("button: (%d), x(%d) y(%d)\n",button,x,y);
	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
		{
		if (button == 1)
		{
			env->key.move_sides += (x - WIN_W * 0.5) * RATIO/ (env->key.zoom * WIN_W);
			env->key.move_updown += (y - WIN_H * 0.5) / (env->key.zoom * WIN_H);
			env->key.zoom += 0.2;
			printf("%f : %f \n",env->key.move_sides,env->key.move_updown);
		}
		if (button == 2 && env->key.zoom > 0.3)
		{
			env->key.zoom -= 0.2;	
		}
		env->fnct.expose_hook(env);
	}
	return (0);
}

int		def_mouse_move_hook(int x, int y, void *param)
{
	t_env *const env = param;

	while (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
	{
		
		env->key.x = (x - WIN_W /2.0) * RATIO / (1.2 * env->key.zoom * WIN_W) + env->key.move_sides;
		env->key.y = (y - WIN_H /2.0) / (1.2 * env->key.zoom * WIN_H) + env->key.move_updown;
		env->fnct.expose_hook(env);
		return (0);
	}
	return (0);
}
