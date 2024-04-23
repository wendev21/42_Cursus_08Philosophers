# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:46:47 by wecorzo-          #+#    #+#              #
#    Updated: 2024/04/22 15:33:29 by wecorzo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES =  handle_error.c\
		   philo_utils.c\
		   initiation.c\
		   threads.c\
		   set_muthex.c\
		   ft_usleep.c\
		   routine.c\
		   death.c\
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
