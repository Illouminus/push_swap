/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:50:03 by edouard           #+#    #+#             */
/*   Updated: 2024/02/20 14:34:48 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Pushes the top node from one stack to another.
 * @param dst The destination stack to push to.
 * @param src The source stack to push from.
 */
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

/**
 * Executes the 'pa' operation:
 *  pushes the top node of stack b onto stack a.
 * Optionally prints the operation.
 * @param a Pointer to the top of stack a.
 * @param b Pointer to the top of stack b.
 * @param print Flag to print the operation.
 */
void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

/**
 * Executes the 'pb' operation:
 * pushes the top node of stack a onto stack b.
 * Optionally prints the operation.
 * @param b Pointer to the top of stack b.
 * @param a Pointer to the top of stack a.
 * @param print Flag to print the operation.
 */
void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

/**
 * Moves the smallest node to the top of stack 'a'.
 * @param a Stack 'a' to modify.
 */
void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
