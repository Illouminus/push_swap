/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:05:37 by edouard           #+#    #+#             */
/*   Updated: 2024/01/17 16:28:11 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sets the index and median status for each node in the stack.
 * @param stack The stack whose nodes are to be indexed.
 */
void current_index(t_stack_node *stack)
{
	int i = 0;
	int median;

	if (!stack)
		return;

	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_median = i <= median;
		stack = stack->next;
		++i;
	}
}

/**
 * Sets the target node for each node in stack 'a' based on its position relative to stack 'b'.
 * @param a Stack 'a' to set target nodes for.
 * @param b Stack 'b' to use as reference.
 */
static void set_target_a(t_stack_node *a, t_stack_node *b)
{
	while (a)
	{
		long best_match_index = LONG_MIN;
		t_stack_node *current_b = b;
		t_stack_node *target_node;

		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}

		a->target_node = (best_match_index == LONG_MIN) ? find_max(b) : target_node;
		a = a->next;
	}
}

/**
 * Analyzes and assigns the cost of pushing each node in stack 'a' to its target position in stack 'b'.
 * @param a Stack 'a' for cost analysis.
 * @param b Stack 'b' for reference.
 */
static void cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int len_a = stack_len(a);
	int len_b = stack_len(b);

	while (a)
	{
		a->push_cost = a->above_median ? a->index : len_a - a->index;
		a->push_cost += a->target_node->above_median ? a->target_node->index : len_b - a->target_node->index;
		a = a->next;
	}
}

/**
 * Identifies and marks the cheapest node to push in the stack.
 * @param stack The stack to evaluate for the cheapest push cost.
 */
void set_cheapest(t_stack_node *stack)
{
	long cheapest_value = LONG_MAX;
	t_stack_node *cheapest_node = NULL;

	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}

	if (cheapest_node)
		cheapest_node->cheapest = true;
}

/**
 * Initializes nodes in stack 'a' by setting their indices, targets, costs, and identifying the cheapest node.
 * @param a Stack 'a' to initialize.
 * @param b Stack 'b' used as reference.
 */
void init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
