CC			= gcc
CFLAG		= -Wall -Werror -Wextra

STACK_SRC	= group_moves.c push_swap_moves.c rotate_moves.c stack_generator.c
STACK_HDRS	= stack_management.h
SRCS		= main.c chunking_algo.c sorting_algo.c $(STACK_SRC)
OBJS		= $(patsubst %.c,%.o,$(SRCS))

HDRS		= main.h algos.h $(STACK_HDRS)

B_SRCS		= checker_bonus.c $(STACK_SRC)
B_OBJS		= $(patsubst %.c,%.o,$(B_SRCS))
B_HRDS		= $(STACK_HDRS)

LIBFT		= libft/libft.a

NAME		= push_swap
B_NAME		= checker

%.o			: %.c $(HDRS)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME)		:$(LIBFT) $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -lft -Llibft -o $(NAME)


all			:$(NAME) bonus

$(LIBFT)	:
	make -C libft

bonus		: $(B_NAME)

$(B_NAME)	:$(B_OBJS) $(B_HRDS) $(LIBFT)
	$(CC) $(CFLAG) $(B_OBJS) -lft -Llibft -o $(B_NAME)	

clean		:
	rm -f $(OBJS) $(B_OBJS)
	make -C libft fclean

fclean		: clean
	rm -f $(NAME) $(B_NAME)

re			:fclean $(NAME)

.PHONY		: all bonus clean fclean re 
