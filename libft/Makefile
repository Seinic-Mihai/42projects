# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mseinic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 16:27:43 by mseinic           #+#    #+#              #
#    Updated: 2015/11/28 19:39:54 by mseinic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_LIST = \
	ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
	ft_isprint ft_memchr ft_memcmp ft_memset ft_strcat \
	ft_strcmp ft_strcpy ft_strdup ft_strlen ft_strlcat \
	ft_strchr ft_strncmp ft_strncpy ft_tolower  \
	ft_toupper ft_atoi ft_memcpy ft_memmove ft_memccpy \
	ft_strncat ft_strnstr ft_strrchr ft_strstr \
	ft_itoa ft_putchar_fd ft_putnbr_fd ft_strdel ft_strjoin ft_strnew \
	ft_memalloc ft_putendl ft_putstr ft_strequ ft_strmap ft_strsplit \
	ft_memdel ft_putendl_fd ft_putstr_fd ft_striter ft_strmapi ft_strsub \
	ft_putchar ft_putnbr ft_strclr ft_striteri ft_strnequ ft_strtrim \
	ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew	

HEADERS_LIST = libft

SRC_PATH = ./

HEADERS_PATH = ./

CACHE_PATH = ./cache/

COMPILER = clang

CFLAGS = -Wall -Werror -Wextra

ALL_FLAGS = $(CFLAGS) -I $(HEADERS_PATH)

#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#
SRC = $(addprefix $(SRC_PATH),$(addsuffix .c,$(SRCLIST)))
OBJ = $(addprefix $(CCHPATH),$(addsuffix .o,$(SRCLIST)))
HDR = $(addprefix $(HDRPATH),$(addsuffix .h,$(HDRLIST)))
#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#

#-----------------COLORS------------------#
#-------B = Bolt---------#
#-------I = Intense------#
#-------U = Underline----#
U_Green = "\033[4;32m"
B_I_Red = "\033[1;91m"
Yellow  = "\033[0;33m"
END     = "\033[0m"
#-----------------COLORS------------------#


all: $(NAME)

#======= compiling NAME file =======
$(NAME): $(OBJ)
	@echo $(Yellow) " Compiling --------> $@ <--------" $(END)
	@ar -cvq $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(U_Green) " !!! Ready !!!" $(END)

#======= compiling *.c in *.o ======
$(CACHE_PATH)

clean:
	/bin/rm -rf $(FILES_O)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
