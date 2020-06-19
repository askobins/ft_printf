# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askobins <askobins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 17:21:25 by askobins          #+#    #+#              #
#    Updated: 2020/06/19 19:11:41 by askobins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = clang

FLAGS = -Wall -Werror -Wextra

INC = include/libprintf.h

SRC = src/ft_printf.c\
		   src/heavylifting.c\
		   src/helpers.c\
		   src/lft.c\
		   src/p_ftypes.c\
		   src/p_itypes.c\
		   src/p_stypes.c

OBJ = $(SRC:.c=.o)

ACCENT = $(shell echo "\033[1;32m")

END = $(shell echo "\033[0m")

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@ar rcs $(NAME) $(OBJ)
	@printf "Done!\n"

%.o: %.c
	@printf "compiling $(ACCENT)$^$(END)\n"
	@$(CC) -c $(FLAGS) -o $@ $^

clean:
	@printf "Cleaning up\n"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: all
