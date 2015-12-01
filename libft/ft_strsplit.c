/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:06:18 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/30 16:34:24 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_words(const char *str, char separator)
{
	size_t			nb;
	size_t			i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != separator)
			nb++;
		i++;
	}
	return (nb);
}

char				**ft_strsplit(const char *s, char c)
{
	char			**ret;
	size_t			i;
	size_t			j;
	size_t			len;

	if (!s || !c || !(ret = ft_memalloc(ft_count_words(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			ret[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	ret[j] = 0;
	return (ret);
}
