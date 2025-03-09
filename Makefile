SRC = first_stage.c functions_utils.c linked_list_utils.c\
	more_operations.c parsing.c operations.c\
	push_swap.c quick_sort.c seconde_stage.c\
	simple_sort.c sorting_large_stack.c\
	split.c str_utils.c
BSRC = checker/checker_bonus.c checker/function_utils_bonus.c\
		checker/get_next_line_utils.c checker/get_next_line.c\
		checker/linked_list_utils_bonus.c checker/more_operations_bonus.c\
		checker/operations_bonus.c checker/parsing_bonus.c checker/split_bonus.c\
		checker/str_utils_bonus.c 
OBJS = ${SRC:.c=.o}
BOBJS = ${BSRC:.c=.o}
BNAME = checker_bns
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${BNAME} : ${BOBJS}
	${CC} ${CFLAGS} -o ${BNAME} ${BOBJS}

bonus : ${BNAME}

clean :
	rm -f ${OBJS} ${BOBJS}

fclean : clean
	rm -f ${NAME} ${BNAME}

re : fclean all

.PHONY : all clean fclean re