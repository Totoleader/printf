# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macote <macote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 08:52:26 by macote            #+#    #+#              #
#    Updated: 2023/02/27 09:25:44 by macote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE_DIR = $(PWD)
LIBFT_DIR = $(MAKE_DIR)/libft
NAME    = libftprintf.a
LIBFT   = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRCS = ft_printf.c flag_actions/alpha_flags.c flag_actions/num_flags.c \
		flag_actions/unsigned_num_flags.c flag_actions/hexa_flags.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): libft $(OBJS)
	ar -rcs $(NAME) $(OBJS)
libft:
	cd libft && $(MAKE) && cp libft.a ../libftprintf.a
clean:
	rm -f $(LIBFT_DIR)/*.o
	rm -f flag_actions/*.o
	rm -f *.o
fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)/$(LIBFT)
re: fclean all
.PHONY: all libft clean fclean re
