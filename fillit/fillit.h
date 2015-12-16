/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:00:19 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/16 12:56:06 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void			clear_tab(char **tab);
char			**check_file(int fd);
void			reset_tetris(char *tetris);
void			reset_all_tetris(char **tetris);
int				is_correct_tetris(char *tetris, int i, char letter);
int				set_tetris(char *tetris, int i, char *solution, int j);
char			*solver(char **tetris);

#endif
