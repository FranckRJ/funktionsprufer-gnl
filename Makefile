# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/11/26 15:39:01 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test-gnl
CFLAGS = -Wall -Wextra --std=c++14
SRCS = $(wildcard *.cpp)
SRCS += $(wildcard funktionsprufer/*.cpp)
TPPS = $(wildcard *.tpp)
TPPS += $(wildcard funktionsprufer/*.tpp)
INCLUDES = $(wildcard *.hpp)
INCLUDES += $(wildcard funktionsprufer/*.hpp)
INCLUDES += $(wildcard gnl/*.h)

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES) $(TPPS)
	g++ $(CFLAGS) $(SRCS) -o $(NAME) -I gnl/libft/includes -L gnl/libft -L gnl -lft -lgnl

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
