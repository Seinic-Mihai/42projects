/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:17:07 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/29 10:22:27 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char *)ft_memalloc(len + 1)))
		return (0);
	str = ft_strncpy(str, (s + start), len);
	str[len] = '\0';
	return (str);
}
