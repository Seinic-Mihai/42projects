/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:42:01 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/29 11:34:09 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	l;

	if (s == NULL)
		return (0);
	l = 0;
	i = ft_strlen(s);
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
		l++;
	if (i == 0 && s[l] == '\0')
		return (ft_strnew(0));
	if (!(str = (char *)ft_memalloc(i + 1)))
		return (0);
	ft_memcpy(str, s + l, i - l);
	str[i] = '\0';
	return (str);
}
