/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:16:14 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/26 18:36:42 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	if (size == 0)
		return ("");
	if (!(str = (char *)ft_memalloc(size)))
		return (0);
	ft_bzero(str, size);
	return (str);
}
