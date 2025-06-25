NAME = minishell

CC			= cc

CCFLAGS 	= -Wall -Wextra -Werror

HEADERS 	= includes

HEADER_DEP 	= includes/minishell.h includes/tokenizer.h

SRC_PATH	= ./src/

OBJ_PATH	= ./obj/

SRCS 		= main.c parsing/check_quotes.c parsing/cmds.c \
			  parsing/count_space.c parsing/ft_split.c parsing/ft_split_utils.c \
			  parsing/identification_aux.c parsing/identification.c parsing/insert_space.c \
			  parsing/list_utils.c parsing/parsing.c parsing/path.c \
			  signaux/handler.c parsing/print.c parsing/quotes.c \
			  parsing/commands_utils.c parsing/tokenizer.c exec/pipes.c \
			  env/lst_copy.c env/env_utils.c env/env_struct_utils.c \
			  env/free.c env/char_ptr_copy.c \
			  
OBJ			= ${SRCS:.c=.o}

OBJS 		= $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_DIR	= ./libft

LIBFT		= ./libft/libft.a

all:		${OBJ_PATH} ${NAME}

${OBJ_PATH}%.o: ${SRC_PATH}%.c ${HEADER_DEP}
				${CC} ${CCFLAGS} -I${HEADERS} -c $< -o $@

${OBJ_PATH}:
			mkdir $@
			mkdir $@parsing
			mkdir $@signaux
			mkdir $@exec
			mkdir $@env

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
