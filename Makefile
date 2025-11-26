# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 14:11:48 by mkazuhik          #+#    #+#              #
#    Updated: 2025/08/09 03:11:45 by mkazuhik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

COMMON_SRCS = src/execute.c src/utils.c src/get_next_line.c src/ft_error.c
MANDATORY_SRCS = src/pipex.c ${COMMON_SRCS}
BONUS_SRCS = bonus/pipex_bonus.c ${COMMON_SRCS}

ifdef BONUS
SRCS = ${BONUS_SRCS}
else
SRCS = ${MANDATORY_SRCS}
endif

OBJS = ${SRCS:.c=.o}

all: ${NAME}

bonus:
	${MAKE} BONUS=1 all

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}

clean:
	${RM} ${MANDATORY_SRCS:.c=.o} ${BONUS_SRCS:.c=.o}
	${MAKE} clean -C libft

fclean: clean
	${RM} ${NAME}
	${RM} libft/libft.a

re: fclean all

.PHONY: all bonus clean fclean re