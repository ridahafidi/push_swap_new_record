SRC = first_stage.c functions_utils.c linked_list_utils.c\
	more_operations.c parsing.c operations.c\
	push_swap.c quick_sort.c seconde_stage.c\
	simple_sort.c sorting_large_stack.c\
	split.c str_utils.c
OBJS = ${SRC:.c=.o}
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean :
	rm -f *.o

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re