# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:46:47 by wecorzo-          #+#    #+#              #
#    Updated: 2024/04/16 16:09:12 by wecorzo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES =  handle_error.c\
		   philo_utils.c\
		   initiation.c\
		   main.c

OBJS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

start:
	@make all

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: start all clean fclean re #bonus
