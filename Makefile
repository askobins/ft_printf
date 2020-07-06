# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askobins <askobins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 17:21:25 by askobins          #+#    #+#              #
#    Updated: 2020/07/06 21:51:19 by askobins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

INC = inc/libftprintf.h

SRCDIR = src

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/,\
	  ft_printf.o\
	  heavylifting.o\
	  helpers.o\
	  lft.o\
	  p_ftypes.o\
	  p_itypes.o\
	  p_stypes.o)

GREEN = $(shell echo "\033[1;32m")

BLUE =  $(shell echo "\033[1;34m")

BLUE2 = $(shell echo "\033[34m")

END =   $(shell echo "\033[0m")

vpath %.c $(SRCDIR)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@ar rcs $(NAME) $(OBJ)
	@printf "$(BLUE)Done!$(END)\n"

$(OBJDIR)/%.o: %.c $(INC) $(OBJDIR)
	@printf "$(BLUE2)compiling $(GREEN)$<$(END)\n"
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR):
	@mkdir $(OBJDIR)

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
