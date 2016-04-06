/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:09:46 by mseinic           #+#    #+#             */
/*   Updated: 2016/04/03 19:36:29 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <fractol.h>

int		def_key_hook(int keycode, void *param)
{
	t_env *const env = param;
	ft_putstr("Key code :");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		env->key.move_sides -= 0.2 / env->key.zoom;
	if (keycode == 124)
		env->key.move_sides += 0.2 / env->key.zoom;
	if (keycode == 126)
		env->key.move_updown -= 0.2/ env->key.zoom;
	if (keycode == 125)
		env->key.move_updown += 0.2/ env->key.zoom;
	if (keycode == 69 && env->maxiter <= 500)
		env->maxiter ++;
	if (keycode == 78 && env->maxiter > 9)
		env->maxiter --;
	if (keycode == 18)
		env->key.zoom += 0.2;
	env->fnct.expose_hook(env);
	return (0);
}
