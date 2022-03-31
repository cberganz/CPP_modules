# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:03:42 by cberganz          #+#    #+#              #
#    Updated: 2022/03/31 12:07:35 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= AccountManager

HEADER		= Account.hpp

CC		= clang++

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

SRCS	 	= Account.cpp tests.cpp

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY : all clean fclean re
