# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:03:42 by cberganz          #+#    #+#              #
#    Updated: 2022/03/31 12:39:39 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= AccountManager

CC		= clang++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS	 	= tests.cpp\
		  Account.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY : all clean fclean re
