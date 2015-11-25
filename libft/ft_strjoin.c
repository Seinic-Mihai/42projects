/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:38:18 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 21:00:45 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!(str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	str = ft_strcat((char *)s1, (char*)s2);
	return (str);
}
