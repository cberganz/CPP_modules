# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:03:42 by cberganz          #+#    #+#              #
#    Updated: 2022/04/01 00:37:09 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= My_Awesome_PhoneBook

CC		= clang++

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

SRCS	 	= PhoneBook.cpp Contact.cpp main.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
