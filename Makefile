# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askobins <askobins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 17:21:25 by askobins          #+#    #+#              #
#    Updated: 2020/07/14 01:11:08 by askobins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc #unnecessary but im desperate

NAME = libftprintf.a

FILES = lft\
		helpers\
		output\
		p_stypes\
		p_itypes\
		p_ftypes\
		heavylifting\
		ft_printf

INCDIR = inc/

SRCDIR = src/

OBJDIR = obj/

OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(FILES)))

CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

GREEN = $(shell echo "\033[1;32m")

BLUE =  $(shell echo "\033[1;34m")

BLUE2 = $(shell echo "\033[34m")

END =   $(shell echo "\033[0m")

vpath %.c $(SRCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@printf "$(BLUE)Done!$(END)\n"

$(OBJDIR)%.o: %.c $(INC)
	@printf "$(BLUE2)compiling $(GREEN)$<$(END)\n"
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@printf "$(BLUE)Cleaning up$(END)\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all #breaks multithreading but again, desperate

bonus: all

.PHONY: all clean fclean re
