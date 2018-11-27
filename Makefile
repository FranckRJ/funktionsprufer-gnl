# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwerner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:25:16 by fwerner           #+#    #+#              #
#    Updated: 2018/11/27 13:38:36 by fwerner          ###   ########.fr        #
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
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CFLAGS) $(OBJS) -o $(NAME) -I gnl/libft/includes -L gnl/libft -L gnl -lft -lgnl

%.o : %.cpp $(INCLUDES) $(TPPS)
	g++ $(CFLAGS) -c $< -o $@ -I gnl/libft/includes

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
