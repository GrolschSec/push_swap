NAME = push_swap

SRC = main.c \
	stack.c \
	init.c \
	error.c \
	free.c \
	ops.c \
	push_swap.c \
	sort_utils.c \
	parse.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	sort_1.c \
	cost_1.c \
	cost_2.c \
	move_1.c \

DIR 		= ${addprefix srcs/,${SRC}}

INCLUDE_DIR	= -I ft

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -g

OBJS		= ${DIR:.c=.o}

FT_LIB	= -L ft -lft

MATH_LIB = -lm

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft
	$(CC) $(CFLAGS) $(OBJS) $(FT_LIB) $(MATH_LIB) -o $(NAME) 

.c.o:
	${CC} ${CFLAGS} ${INCLUDE_DIR} -c $< -o ${<:.c=.o}

clean:
	make clean -C ft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re