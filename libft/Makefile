#ft_strlcat.c
NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_memchr.c ft_memcmp.c ft_memset.c ft_strcat.c \
	ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strlcat.c\
	ft_strchr.c ft_strncmp.c ft_strncpy.c ft_tolower.c \
	ft_toupper.c ft_atoi.c ft_memcpy.c ft_memmove.c ft_memccpy.c\
	ft_strncat.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_strdel.c ft_strjoin.c ft_strnew.c \
	ft_memalloc.c ft_putendl.c ft_putstr.c ft_strequ.c ft_strmap.c ft_strsplit.c \
	ft_memdel.c ft_putendl_fd.c ft_putstr_fd.c ft_striter.c ft_strmapi.c ft_strsub.c \
	ft_putchar.c ft_putnbr.c ft_strclr.c ft_striteri.c ft_strnequ.c ft_strtrim.c

FILES_H = libft.h

FILES_O = ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
	ft_isprint.o ft_memchr.o ft_memcmp.o ft_memset.o ft_strcat.o \
	ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlen.o ft_strlcat.o\
	ft_strncmp.o ft_strncpy.o ft_tolower.o ft_memmove.o\
	ft_toupper.o ft_strchr.o ft_atoi.o ft_memcpy.o ft_memccpy.o\
	ft_strncat.o ft_strnstr.o ft_strrchr.o ft_strstr.o \
	ft_itoa.o ft_putchar_fd.o ft_putnbr_fd.o ft_strdel.o ft_strjoin.o ft_strnew.o \
	ft_memalloc.o ft_putendl.o ft_putstr.o ft_strequ.o ft_strmap.o ft_strsplit.o \
	ft_memdel.o ft_putendl_fd.o ft_putstr_fd.o ft_striter.o ft_strmapi.o ft_strsub.o \
	ft_putchar.o ft_putnbr.o ft_strclr.o ft_striteri.o ft_strnequ.o ft_strtrim.o

FLAGS = -Wall -Werror -Wextra -g

NORME = echo "bingo"

all: F1 F2

F1:
	gcc $(FLAGS) -c $(SRC) $(FILES_H)
	
F2:
	ar -cvq $(NAME) $(FILES_O)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(FILES_O)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
