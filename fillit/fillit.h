/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:00:19 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/09 12:23:39 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int				ft_clear_tab(char **tab);
char			**check_file(int fd);
void			reset_tetriminos(char *tetriminos);
void			reset_all_tetriminos(char **tetriminos);
int				is_tetriminos(char *tetriminos, int i, char letter);
int				set_tetriminos(char *tetriminos, int i, char *solution, int j);
char			*solver(char **tetriminos);

#endif
