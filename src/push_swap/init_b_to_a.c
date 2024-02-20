/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:18 by edouard           #+#    #+#             */
/*   Updated: 2024/02/20 14:26:28 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sets the target node for each node in stack
 *  'b' based on its position relative to stack 'a'.
 * @param a Stack 'a' used for reference.
 * @param b Stack 'b' to set target nodes for.
 */
static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	long			best_match_index;
	t_stack_node	*current_a;
	t_stack_node	*target_node;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/**
 * Initializes nodes in stack 'b' by setting their indices and targets,
	based on their relation to stack 'a'.
 * @param a Stack 'a' used as reference.
 * @param b Stack 'b' to initialize.
 */
void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
