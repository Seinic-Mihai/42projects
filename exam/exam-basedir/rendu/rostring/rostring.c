/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:29:22 by mseinic           #+#    #+#             */
/*   Updated: 2016/02/20 19:39:42 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_bzero(char *str, int size)
{
	while (size > 0)
	{
		*str = '\0';
		str++;
		size--;
	}
}

#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;
	int		size;
	char 	*save;

	save = 0;
	size = 0;
	if (ac == 2)
	{
		size = ft_strlen(av[1]);
		printf("%d\n",size);
		str = (char *)malloc(sizeof(char) * size + 1);
		ft_bzero(str, size + 1);
		save = str;
		if (size > 0)
		{
			size = 0;
		while (av[1][size] != '\0')
		{
			while ((av[1][size] == ' ' || av[1][size] == '\t' ) && av[1][size] != '\0')
				size++;
			while (av[1][size] != ' ' && av[1][size] != '\t' && av[1][size] != '\0')
			{
				*str = av[1][size];
				size++;
				str++;
			}
			if (av[1][size] == ' ' || av[1][size] == '\t')
				*str++ = ' ';
			if (av[1][size] != '\0')
				size++;
		}
		size = 0;
		while (*save != ' ')
		{
			save++;
			size++;
		}
		*save = '\0';
		if (size != 0)
		{
			if (*(save + 1) != ' ' || *(save + 1) != '\t')
			{
		ft_putstr(save + 1);
		ft_putstr(" ");
			}
		ft_putstr(save - size);
		}
		}
		ft_putstr("\n");
	}
	else
		ft_putstr("\n");
	return (0);
}
