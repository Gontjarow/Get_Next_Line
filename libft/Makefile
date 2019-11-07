# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 13:15:52 by ngontjar          #+#    #+#              #
#    Updated: 2019/11/04 17:16:36 by ngontjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c

SRC2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC3 = ft_islower.c ft_isupper.c ft_isspace.c ft_putstrn.c ft_strrev.c ft_print2dstr.c ft_range.c ft_strlcpy.c ft_putstrn_nulls.c ft_strclen.c

SRO1 = $(subst .c,.o,$(SRC1))
SRO2 = $(subst .c,.o,$(SRC2))
SRO3 = $(subst .c,.o,$(SRC3))

TESTSRC = ./test
TESTBIN = ./test/bin

FLAGS = -Wall -Wextra -Werror

# "missing separator"?
# .PHONY re fclean all objects run

all: $(NAME)

$(NAME): $(SRO1) $(SRO2) $(SRO3)
	ar -rv $(NAME) $(SRO1) $(SRO2) $(SRO3)

$(SRO1) $(SRO2) $(SRO3): $(SRC1) $(SRC2) $(SRC3)
	gcc $(FLAGS) -c $(SRC1) $(SRC2) $(SRC3) -Iincludes

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(SRO1) $(SRO2) $(SRO3)
