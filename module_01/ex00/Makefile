# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:03:42 by cberganz          #+#    #+#              #
#    Updated: 2022/03/31 16:51:47 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Zombie

HEADER		= Zombie.hpp

CC			= clang++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS	 	= Zombie.cpp\
		 		 newZombie.cpp\
				 randomChump.cpp\
				 main.cpp

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
