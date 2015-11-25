/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:44:52 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 12:09:37 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tab;
	size_t	size;

	size = ft_strlen(str) + 1;
	if (!(tab = (char *)malloc(size)))
		return (0);
	ft_strcpy(tab, str);
	return (tab);
}
