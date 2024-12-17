NAME = minishell

CC			= cc

CCFLAGS 	= -Wall -Wextra -Werror 

HEADERS 	= .

HEADER_DEP 	= minishell.h

SRC_PATH	= ./src/

OBJ_PATH	= ./obj/

SRCS 		= main.c
			  
OBJ			= ${SRCS:.c=.o}

OBJS 		= $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_DIR	= ./libft

LIBFT		= ./libft/libft.a

all:		${OBJ_PATH} ${NAME}

${OBJ_PATH}%.o: ${SRC_PATH}%.c ${HEADER_DEP}
				${CC} ${CCFLAGS} -I${HEADERS} -c $< -o $@

${OBJ_PATH}:
			mkdir ${OBJ_PATH}

${LIBFT}:
				make -C ${LIBFT_DIR} all

${NAME}:	${LIBFT} ${OBJS}
	${CC} ${CCFLAGS} ${OBJS} -L${LIBFT_DIR} -l:libft.a -lreadline -o ${NAME}
clean:
				make -C ${LIBFT_DIR} clean
				rm -rf ${OBJ_PATH}

fclean:		clean
				make -C ${LIBFT_DIR} fclean
				rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
