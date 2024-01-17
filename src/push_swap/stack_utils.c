/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:19:25 by edouard           #+#    #+#             */
/*   Updated: 2024/01/17 16:28:27 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Calculates and returns the length of a stack.
 * @param stack The stack to measure.
 * @return The length of the stack.
 */
int stack_len(t_stack_node *stack)
{
	int count = 0;

	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return count;
}

/**
 * Returns the last node of a stack.
 * @param stack The stack to examine.
 * @return The last node of the stack, or NULL if the stack is empty.
 */
t_stack_node *find_last(t_stack_node *stack)
{
	if (!stack)
		return NULL;

	while (stack->next)
		stack = stack->next;

	return stack;
}

/**
 * Checks if a stack is sorted in ascending order.
 * @param stack The stack to check.
 * @return true if the stack is sorted, false otherwise.
 */
bool stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return true;

	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return false;
		stack = stack->next;
	}
	return true;
}

/**
 * Finds and returns the node with the minimum value in a stack.
 * @param stack The stack to search.
 * @return The node with the smallest value, or NULL if the stack is empty.
 */
t_stack_node *find_min(t_stack_node *stack)
{
	long min = LONG_MAX;
	t_stack_node *min_node = NULL;

	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return min_node;
}

/**
 * Finds and returns the node with the maximum value in a stack.
 * @param stack The stack to search.
 * @return The node with the largest value, or NULL if the stack is empty.
 */
t_stack_node *find_max(t_stack_node *stack)
{
	long max = LONG_MIN;
	t_stack_node *max_node = NULL;

	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return max_node;
}
