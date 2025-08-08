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
SRCS = src/execute.c src/pipex.c src/utils.c src/get_next_line.c src/ft_error.c
OBJS = ${SRCS:.c=.o}
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${OBJS} libft/libft.a -o ${NAME}

clean:
	${RM} ${OBJS}
	$(MAKE) clean -C libft

fclean: clean
	${RM} ${NAME}
	${RM} libft/libft.a

re: fclean all

.PHONY: all clean fclean re