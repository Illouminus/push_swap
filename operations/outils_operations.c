/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:38:47 by edouard           #+#    #+#             */
/*   Updated: 2024/01/11 09:39:08 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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