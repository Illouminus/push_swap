NAME = push_swap
CHECKER_NAME = checker
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./printf

LIBFT = ./libft/libft.a
LIBFTPRINTF = ./printf/libftprintf.a


SRCS = src/commands/push.c src/commands/rev_rotate.c src/commands/rotate.c \
       src/commands/sort_stacks.c src/commands/sort_three.c src/commands/swap.c \
       src/push_swap/handle_errors.c src/push_swap/init_a_to_b.c src/push_swap/init_b_to_a.c \
       src/push_swap/split.c src/push_swap/stack_init.c src/push_swap/stack_utils.c

PUSH_SWAP_SRCS = src/push_swap/push_swap.c
CHECKER_SRCS = checker_bonus/checker.c

PUSH_SWAP_OBJS = $(SRCS:.c=.o) $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(SRCS:.c=.o) $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(LIBFTPRINTF) $(LIBFT)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(LIBFTPRINTF) $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJS) $(LIBFTPRINTF) $(LIBFT)


$(LIBFT):
	make -C ./libft

$(LIBFTPRINTF):
	make -C ./printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	make -C ./printf clean
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(CHECKER_NAME)
	make -C ./printf fclean
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
