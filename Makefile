NAME = push_swap
CC = gcc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./printf

LIBFTPRINTF = ./printf/libftprintf.a

SRCS = operations/init_b.c operations/move.c operations/outils_operations.c \
       operations/push.c operations/rotate.c operations/rrr_rotate.c \
       operations/sort_three.c operations/swap.c \
       check_errors.c ft_atoi.c ft_calloc.c ft_split.c init_stack.c \
       push_swap.c sort_stack.c utils.c

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
