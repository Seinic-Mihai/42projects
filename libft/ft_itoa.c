/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:15:51 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/27 20:27:56 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_verif(int nb)
{
	int temp;
	size_t char_nb;

	char_nb = 0;
	temp = nb;
	if (nb < 0)
	{
		char_nb++;
		temp = -nb;
	}
	while (temp != 0)
	{
		temp /= 10;
		char_nb++;
	}
	return (char_nb);
}

char				*ft_itoa(int nb)
{
	char	*str;
	int		char_nb;
	char	sign;

	sign = '0';
	char_nb = 0;
	if (nb == 0)
		return("0");
	if (nb == ENT_MIN)
		return ("-2147483648");
	char_nb = ft_verif(nb);
	if (nb < 0)
	{
		sign = '-';
		nb = -nb;
	}
	if (!(str = (char *)ft_memalloc(char_nb + 1)))
		return (0);
	if (sign == '-')
		str[0] = '-';
	str[char_nb] = '\0';
	while (nb != 0)
	{
		str[--char_nb] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
