/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:00:49 by edouard           #+#    #+#             */
/*   Updated: 2024/02/20 14:29:28 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Swaps the top two nodes of a stack.
 * @param head The head of the stack to swap the top two nodes.
 */
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

/**
 * Swaps the top two nodes of stack
 * 'a' and prints the operation if instructed.
 * @param a The stack 'a' to perform the swap on.
 * @param print Flag to indicate whether to print the operation.
 */
void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

/**
 * Swaps the top two nodes of stack 'b'
 * and prints the operation if instructed.
 * @param b The stack 'b' to perform the swap on.
 * @param print Flag to indicate whether to print the operation.
 */
void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

/**
 * Simultaneously swaps the top two nodes of both stacks 'a' and 'b',
	and prints the operation if instructed.
 * @param a The stack 'a' to perform the swap on.
 * @param b The stack 'b' to perform the swap on.
 * @param print Flag to indicate whether to print the operation.
 */
void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
