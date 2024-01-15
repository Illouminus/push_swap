/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:38:47 by edouard           #+#    #+#             */
/*   Updated: 2024/01/15 14:58:42 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *find_biggest(t_stack *stack)
{
	t_stack *biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->value > biggest->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

void current_index(t_stack *stack)
{
	int i;
	int median;

	i = 0;
	if (!stack)
		return;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->is_median = true;
		else
			stack->is_median = false;
		stack = stack->next;
		i++;
	}
}

void set_target_a(t_stack *a, t_stack *b)
{
	t_stack *current_b;
	t_stack *target;
	long best_index;

	while (a)
	{
		best_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->index > best_index)
			{
				best_index = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

t_stack *find_min(t_stack *stack)
{
	long min;
	t_stack *min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack *find_max(t_stack *stack)
{
	long max;
	t_stack *max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}