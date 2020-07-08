# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askobins <askobins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 17:21:25 by askobins          #+#    #+#              #
#    Updated: 2020/07/08 19:46:12 by askobins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

INC = inc/libftprintf.h

SRCDIR = src/

OBJDIR = obj/

OBJ = $(addprefix $(OBJDIR),\
	  lft.o\
	  helpers.o\
	  heavylifting.o\
	  p_stypes.o\
	  p_itypes.o\
	  p_ftypes.o\
	  ft_printf.o)

GREEN = $(shell echo "\033[1;32m")

BLUE =  $(shell echo "\033[1;34m")

BLUE2 = $(shell echo "\033[34m")

END =   $(shell echo "\033[0m")

vpath %.c $(SRCDIR)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(INC)
	@ar rcs $(NAME) $(OBJ)
	@printf "$(BLUE)Done!$(END)\n"

$(OBJDIR)%.o: %.c $(INC)
	@printf "$(BLUE2)compiling $(GREEN)$<$(END)\n"
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@printf "$(BLUE)Cleaning up$(END)\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all


bonus: all

.PHONY: all clean fclean re
