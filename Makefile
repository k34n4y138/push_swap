CC			= gcc
CFLAG		= -Wall -Werror -Wextra

SRCS		= main.c group_moves.c push_swap_moves.c rotate_moves.c stack_generator.c
OBJS		= $(patsubst %.c,%.o,$(SRCS))

HDRS		= main.h stack_management.h

B_SRCS		=
B_OBJS		=
B_HRDS		=

LIBFT		= libft/libft.a

NAME		= push_swap


%.o			: %.c $(HDRS)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME)		:$(LIBFT) $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -lft -Llibft -o $(NAME)


all			:$(NAME)

$(LIBFT)	:
	make -C libft

bonus		:$(B_SRCS) $(B_HRDS) $(LIBFT)
	$(CC) $(CFLAG) $(B_SRCS) -lft -LIBFT -o $(NAME)	

clean		:
	rm -f $(OBJS)
	make -C libft fclean

fclean		: clean
	rm -f $(NAME)

re			:fclean $(NAME)

.PHONY		=$(NAME) all bonus clean fclean re $(LIBFT)
