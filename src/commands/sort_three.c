/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:59:39 by edouard           #+#    #+#             */
/*   Updated: 2024/01/17 16:33:10 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sorts a stack 'a' containing exactly three nodes.
 * @param a The stack to be sorted.
 */
void sort_three(t_stack_node **a)
{
	t_stack_node *biggest_node = find_max(*a);

	// Rotate or reverse rotate the stack based on the position of the biggest node
	if (biggest_node == *a)
		ra(a, false); // Rotate if the biggest node is at the top
	else if ((*a)->next == biggest_node)
		rra(a, false); // Reverse rotate if the biggest node is in the middle

	// Swap the top two nodes if necessary to achieve order
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false); // Swap if the top node is greater than the second node
}

int ft_isdigit(int c)

{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
