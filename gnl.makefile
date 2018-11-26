# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/11/26 15:39:59 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CFLAGS = -Wall -Wextra -Werror
INCLUDE_BASE_DIR = .
SRC_BASE_DIR = .
INCLUDES_BASE = get_next_line.h
SRCS_BASE = get_next_line.c
SRCS = $(addprefix $(SRC_BASE_DIR)/,$(SRCS_BASE))
INCLUDES = $(addprefix $(INCLUDE_BASE_DIR)/,$(INCLUDES_BASE))
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	gcc $(CFLAGS) -I libft/includes -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
