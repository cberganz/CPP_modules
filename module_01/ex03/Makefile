# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:03:42 by cberganz          #+#    #+#              #
#    Updated: 2022/03/31 16:50:53 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= HumanBattle

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS	 	= HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

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
