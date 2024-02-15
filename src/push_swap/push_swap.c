/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:10:17 by edouard           #+#    #+#             */
/*   Updated: 2024/02/15 15:16:23 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Main function to sort a given set of numbers in ascending order.
 * @param argc Argument count.
 * @param argv Argument vector containing numbers to sort.
 * @return int Returns 0 on successful execution, 1 on error.
 */
int main(int argc, char **argv)
{
	t_stack_node *a = NULL; // Initialize stack 'a'
	t_stack_node *b = NULL; // Initialize stack 'b'

	// Check for no input or only one argument
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	if (argc == 2)
		argv = ft_split(argv[1], ' ');

	init_stack_a(&a, argv + 1);

	if (!stack_sorted(a))
	{
		int len_a = stack_len(a);
		// Handle small stacks with simple cases
		if (len_a == 2)
			sa(&a, false); // Swap for two elements
		else if (len_a == 3)
			sort_three(&a); // Sort three elements
		else
			sort_stacks(&a, &b); // Sort larger stacks
	}
	free_stack(&a);
	return (0);
}
