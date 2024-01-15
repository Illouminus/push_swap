#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <stdint.h>
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
void sort_three(t_stack **a);
void ra(t_stack **a, bool print);
void rb(t_stack **b, bool print);
void rr(t_stack **a, t_stack **b, bool print);
void sort_stack(t_stack **a, t_stack **b);
void current_index(t_stack *stack);
void set_target_a(t_stack *a, t_stack *b);
t_stack *find_min(t_stack *stack);
t_stack *find_max(t_stack *stack);
t_stack *get_cheapest(t_stack *stack);
t_stack *find_cheapest(t_stack *stack);
void ready_push(t_stack **stack, t_stack *top_node, char stack_name);
void rotate_stack(t_stack **stack);
void ra(t_stack **a, bool print);
void rb(t_stack **b, bool print);
void rr(t_stack **a, t_stack **b, bool print);
void rev_rotate(t_stack **stack);
void rra(t_stack **a, bool print);
void rrb(t_stack **b, bool print);
void pa(t_stack **a, t_stack **b, bool print);
void pb(t_stack **b, t_stack **a, bool print);
void push(t_stack **dst, t_stack **src);
void rrr(t_stack **a, t_stack **b, bool print);
void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void move_a_to_b(t_stack **a, t_stack **b);
void move_b_to_a(t_stack **a, t_stack **b);
void set_target_b(t_stack *a, t_stack *b);
void init_nodes_a(t_stack *a, t_stack *b);
void init_nodes_b(t_stack *a, t_stack *b);
void min_on_top(t_stack **a);
void	swap(t_stack **head);
void	sa(t_stack	**a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
int error_syntax(char *str);
int check_duplicates(t_stack *a, int num);
void free_stack(t_stack *a);
void exit_error(t_stack *a);
#endif