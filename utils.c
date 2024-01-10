/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:12:35 by edouard           #+#    #+#             */
/*   Updated: 2024/01/10 18:12:46 by edouard          ###   ########.fr       */
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