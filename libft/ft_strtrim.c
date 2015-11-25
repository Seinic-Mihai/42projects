/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:42:01 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 21:17:02 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *str;
	size_t i;

	i = ft_strlen(s);
	if (!(str = ft_memalloc(i + 1)))
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
		i--;
	}
	return (ft_memcpy(str, s, i));
}
