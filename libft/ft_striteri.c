/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:34:45 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/27 21:24:02 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char * const save = s;

	if (s != NULL && f != NULL)
	{
		while (*s != '\0')
		{
			(*f)(s - save, s);
			s++;
		}
	}
}
