/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:06:34 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/27 17:33:38 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimchr(char const *s, char chr)
{
	char *str;
	size_t i;
	size_t l;

	l = 0;
	i = ft_strlen(s);
	while (s[i - 1] == chr)
	{
		i--;
	}
	while (s[l] == chr)
	{
		l++;
	}
	if (i == 0 && s[l] == '\0')
		return ("");
	if (!(str = (char *)ft_memalloc(i + 1)))
		return (0);
	return (ft_strncpy(str, s + l, i - l));
}
