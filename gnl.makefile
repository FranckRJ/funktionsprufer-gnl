# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/11/27 15:06:53 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = libgnl-1.a
NAME_2 = libgnl-2.a
NAME_10 = libgnl-10.a
NAME_32 = libgnl-32.a
NAME_100 = libgnl-100.a
NAME_9999 = libgnl-9999.a
NAME_10000000 = libgnl-10000000.a
CFLAGS = -Wall -Wextra -Werror
INCLUDE_BASE_DIR = .
SRC_BASE_DIR = .
INCLUDES_BASE = get_next_line.h
SRCS_BASE = get_next_line.c
SRCS = $(addprefix $(SRC_BASE_DIR)/,$(SRCS_BASE))
INCLUDES = $(addprefix $(INCLUDE_BASE_DIR)/,$(INCLUDES_BASE))
OBJS = $(notdir $(SRCS:.c=.o))

$(NAME_1): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rcs $(NAME_1) $(OBJS)

$(NAME_2): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rcs $(NAME_2) $(OBJS)

$(NAME_10): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rcs $(NAME_10) $(OBJS)

$(NAME_32): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rcs $(NAME_32) $(OBJS)

$(NAME_100): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rcs $(NAME_100) $(OBJS)

$(NAME_9999): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rcs $(NAME_9999) $(OBJS)

$(NAME_10000000): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rcs $(NAME_10000000) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
