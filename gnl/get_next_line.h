/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:01:41 by mseinic           #+#    #+#             */
/*   Updated: 2016/01/08 20:22:30 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

# ifndef NULL
#	define NULL ((void*)0)
# endif

# ifndef BUFF_SIZE
#	define BUFF_SIZE 1
# endif

typedef struct		s_data
{
	int				fd;
	char			*data;
}					t_data;

int get_next_line(int const fd, char **line);
#endif
