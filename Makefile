# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atabiti <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 11:18:45 by atabiti           #+#    #+#              #
#    Updated: 2022/01/13 10:51:19 by atabiti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME : client server
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	CC FLAGS client.c server.c
clean :
	rm server client
fclean : clean

re : fclean all
