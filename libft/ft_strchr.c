/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:08:14 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/27 17:34:33 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = 0;
	if (*s == c)
		return (ptr = (char*)s);
	while (*s++)
		if (*s == c)
			return (ptr = (char *)s);
	return (ptr);
}
