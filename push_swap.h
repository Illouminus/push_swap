#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Standard libraries
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Local libraries
#include "./printf/ft_printf.h"

// Structure for stack representation
typedef struct s_stack
{
	int value;						  // Value of the stack node
	int index;						  // Index in the stack
	int push_cost;					  // Cost to push to this node
	bool is_median;				  // Flag for median status
	bool cheapest;					  // Flag for cheapest status
	struct s_stack *target_node; // Target node for operations
	struct s_stack *next;		  // Next node in the stack
	struct s_stack *prev;		  // Previous node in the stack
} t_stack;

// Utility functions
int ft_isdigit(char c);
long ft_atoi(const char *nptr);
void *ft_calloc(size_t nmemb, size_t size);
void ft_bzero(void *s, size_t n);
char **ft_split(char const *s, char c);

// Stack initialisation and management
void init_stack_a(t_stack **a, char **argv);
void add_node_append(t_stack **a, int num);
void free_stack(t_stack *a);
int stack_len(t_stack *stack);
bool stack_is_sorted(t_stack *stack);
t_stack *find_last(t_stack *stack);
void exit_error(t_stack *a);

// Stack operations
void swap(t_stack **head);
void sa(t_stack **a, bool print);
void sb(t_stack **b, bool print);
void ss(t_stack **a, t_stack **b, bool print);
void push(t_stack **dst, t_stack **src);
void pa(t_stack **a, t_stack **b, bool print);
void pb(t_stack **b, t_stack **a, bool print);
void rotate_stack(t_stack **stack);
void ra(t_stack **a, bool print);
void rb(t_stack **b, bool print);
void rr(t_stack **a, t_stack **b, bool print);
void rev_rotate(t_stack **stack);
void rra(t_stack **a, bool print);
void rrb(t_stack **b, bool print);
void rrr(t_stack **a, t_stack **b, bool print);

// Sorting functions
void sort_three(t_stack **a);
void sort_stack(t_stack **a, t_stack **b);
void move_a_to_b(t_stack **a, t_stack **b);
void move_b_to_a(t_stack **a, t_stack **b);
void min_on_top(t_stack **a);

// Helper functions for sorting
t_stack *find_biggest(t_stack *stack);
t_stack *find_min(t_stack *stack);
t_stack *find_max(t_stack *stack);
void current_index(t_stack *stack);
void set_target_a(t_stack *a, t_stack *b);
void set_target_b(t_stack *a, t_stack *b);
t_stack *find_cheapest(t_stack *stack);
void ready_push(t_stack **stack, t_stack *top_node, char stack_name);
void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void init_nodes_a(t_stack *a, t_stack *b);
void init_nodes_b(t_stack *a, t_stack *b);

// Validation functions
int error_syntax(char *str);
int check_duplicates(t_stack *a, int num);

#endif // PUSH_SWAP_H
