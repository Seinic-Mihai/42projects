/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:15:51 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 21:38:50 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
 
char    *ft_itoa(int nb)
{
	char *str;
	int i;
	int rest;

	rest = 0;
	i = 0;
	str = malloc(nb);
	while (nb != 0)
	{
		rest = nb % 10;
		str[i++] = (rest > 9) ? (rest - 10) + 'a': rest + '0';
		nb = nb / 10;
	}
	str[i] = '\0';
	return (str);
}
