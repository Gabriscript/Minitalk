# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 13:55:48 by ggargani          #+#    #+#              #
#    Updated: 2025/02/18 13:55:48 by ggargani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${SRCS_SERVER}
	${CC} ${CFLAGS} ${SRCS_SERVER} -o ${NAME_SERVER}

${NAME_CLIENT}: ${SRCS_CLIENT}
	${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${NAME_CLIENT}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re
