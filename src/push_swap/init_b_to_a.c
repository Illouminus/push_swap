/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:18 by edouard           #+#    #+#             */
/*   Updated: 2024/01/17 16:28:15 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sets the target node for each node in stack 'b' based on its position relative to stack 'a'.
 * @param a Stack 'a' used for reference.
 * @param b Stack 'b' to set target nodes for.
 */
static void set_target_b(t_stack_node *a, t_stack_node *b)
{
	while (b)
	{
		long best_match_index = LONG_MAX;
		t_stack_node *current_a = a;
		t_stack_node *target_node;

		// Iterate over stack 'a' to find the best target for each node in 'b'
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}

		// Set the target node for the current 'b' node
		b->target_node = (best_match_index == LONG_MAX) ? find_min(a) : target_node;
		b = b->next;
	}
}

/**
 * Initializes nodes in stack 'b' by setting their indices and targets, based on their relation to stack 'a'.
 * @param a Stack 'a' used as reference.
 * @param b Stack 'b' to initialize.
 */
void init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
