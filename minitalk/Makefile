# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafamart <rafamart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 19:23:21 by rafamart          #+#    #+#              #
#    Updated: 2023/10/24 20:30:17 by rafamart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

CC = gcc
FLAGS = -Wall -Wextra -Werror 
RM = rm -f

all: client server

client: 
	${CC} ${FLAGS} client.c functions.c minitalk.h -o ${NAME_CLIENT}

server: 
	${CC} ${FLAGS} server.c functions.c minitalk.h -o ${NAME_SERVER}

clean:
	${RM} ${OBJS_CLIENT} ${OBJS_SERVER} 

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER} 

re: fclean all

.PHONY: all clean fclean bonus
