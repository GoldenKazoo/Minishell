NAME		= libft.a

CC			= cc

CCFLAGS		= -Wall -Wextra -Werror

HEADERS		= .

HEADER_DEP	= libft.h

SRCS_LIBC	= ft_atoi.c ft_bzero.c ft_calloc.c \
			  ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isprint.c ft_memchr.c \
			  ft_memcmp.c ft_memcpy.c ft_memmove.c \
			  ft_memset.c ft_strdup.c ft_strlcat.c \
			  ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			  ft_strrchr.c ft_tolower.c ft_toupper.c \
			  ft_strnstr.c ft_strchr.c 
		  
SRCS_SUPP 	= ft_substr.c ft_itoa.c ft_striteri.c \
			  ft_strmapi.c ft_strjoin.c ft_putchar_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			  ft_strtrim.c ft_split.c
			
SRCS_BONUS 	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

SRCS_M 		= ${SRCS_LIBC} ${SRCS_SUPP}

SRCS_OTHER 	= ft_printf.c get_next_line.c

OBJS_M		= ${SRCS_M:.c=.o}

OBJS_B		= ${SRCS_BONUS:.c=.o}

OBJS_OTHER	= ${SRCS_OTHER:.c=.o}

ifdef WITH_BONUS
OBJS_ALL 	= ${OBJS_M} ${OBJS_B} ${OBJS_OTHER}
else
OBJS_ALL 	= ${OBJS_M} ${OBJS_OTHER}
endif

all:		${NAME}

%.o: %.c	${HEADER_DEP}
				${CC} -I${HEADERS} ${CCFLAGS} -c $< -o $@

${NAME}:	${OBJS_ALL}
				ar rcs ${NAME} ${OBJS_ALL}

bonus:
				make WITH_BONUS=1 all

clean:
				rm -f ${OBJS_M} ${OBJS_B} ${OBJS_OTHER}

fclean: 	clean
				rm -f ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re bonus
