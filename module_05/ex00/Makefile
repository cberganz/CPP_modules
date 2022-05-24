# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:03:42 by cberganz          #+#    #+#              #
#    Updated: 2022/05/23 20:24:00 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucracy

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

SRCS	 	= main.cpp Bureaucrat.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I. -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
