# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 14:11:48 by mkazuhik          #+#    #+#              #
#    Updated: 2025/08/08 14:47:13 by mkazuhik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = src/main.c src/pipex.c src/error.c
INCS = .
NAME = pipex
OBJS = ${SRCS:.c=.o}
RM = rm -f
LIBC = ar rc
LIBR = ranlib
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all