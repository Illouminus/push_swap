#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "./printf/ft_printf.h"

typedef struct s_stack
{
	int value;
	int index;
	int push_cost;
	bool is_median;
	bool cheapest;
	struct s_stack *target_node;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

int ft_isdigit(char c);
char **ft_split(char const *s, char c);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
long ft_atoi(const char *nptr);
t_stack *find_last(t_stack *stack);
void init_stack_a(t_stack **a, char **argv);
void add_node_append(t_stack **a, int num);
bool stack_is_sorted(t_stack *stack);
int stack_len(t_stack *stack);
t_stack *find_biggest(t_stack *stack);
void rotate_stack(t_stack **stack);
void ra(t_stack **a, bool print);
void rb(t_stack **b, bool print);
void rr(t_stack **a, t_stack **b, bool print);
#endif