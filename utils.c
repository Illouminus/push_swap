/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:12:35 by edouard           #+#    #+#             */
/*   Updated: 2024/01/10 22:35:17 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char c)

{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_stack *find_last(t_stack *stack) // Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) // Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

bool stack_is_sorted(t_stack *stack) // Define a function that returns true if the stack is sorted
{
	if (!stack)
		return (1);
	while (stack->next) // Loop until the end of the stack is reached
	{
		if (stack->value > stack->next->value) // If the current node's value is greater than the next node's value
			return (false);							// Return false
		stack = stack->next;							// Move to the next node
	}
	return (true); // Return true
}

int stack_len(t_stack *stack) // Define a function that returns the length of the stack
{
	int len;

	len = 0;
	while (stack) // Loop until the end of the stack is reached
	{
		len++;					// Increment the length
		stack = stack->next; // Move to the next node
	}
	return (len); // Return the length
}