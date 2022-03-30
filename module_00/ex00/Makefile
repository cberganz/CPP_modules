# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 00:22:00 by cberganz          #+#    #+#              #
#    Updated: 2022/03/28 00:28:40 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= megaphone

HEADER		= megaphone.hpp

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS	 	= megaphone.cpp

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -rf $(SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
