/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:42:54 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/05 14:22:19 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fdf.h>

void	draw(void *mlx, void *win)
{
	int x;
	int y;

	y = 49;
	while (++y <= 500)
	{
		x = 49;
		while (++x <= 500)
		{
			if(!(x % 9) && !(y % 9))
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		}
	}
}

int		expose_hook(t_env *env)
{
	draw(env->mlx, env->win);
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
	printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return(0);
}

int	main(int ac, char **av)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 800, 600, "42");
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_loop(env.mlx);
}
