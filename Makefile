NAME = push_swap
CC = gcc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./printf

LIBFTPRINTF = ./printf/libftprintf.a

SRCS = src/commands/push.c src/commands/rev_rotate.c src/commands/rotate.c \
       src/commands/sort_stacks.c src/commands/sort_three.c src/commands/swap.c \
       src/push_swap/handle_errors.c src/push_swap/init_a_to_b.c src/push_swap/init_b_to_a.c \
       src/push_swap/push_swap.c src/push_swap/split.c src/push_swap/stack_init.c src/push_swap/stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

$(LIBFTPRINTF):
	make -C ./printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)
	make -C ./printf clean

fclean: clean
	$(RM) $(NAME)
	make -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re
