/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:02:19 by mseinic           #+#    #+#             */
/*   Updated: 2016/03/25 14:47:05 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <fractol.h>
int		def_expose_hook(void *param)
{
	t_env *const env = param;
//	ft_putstr("\033[0;32mExposing\033[0m\n");
	mlx_clear_window(MLX, WIN);
	env->fnct.paint(env);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_string_put(MLX, WIN, 10, 10, 0x00000000, ft_itoa(env->fractal_type));
	return (0);
}
