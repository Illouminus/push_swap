/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:10:17 by edouard           #+#    #+#             */
/*   Updated: 2024/01/17 16:40:01 by edouard          ###   ########.fr       */
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

	// Handle case where numbers are passed as a single string
	if (argc == 2)
		argv = split(argv[1], ' ');

	// Initialize stack 'a' and handle errors
	init_stack_a(&a, argv + 1);

	// Check if stack 'a' is already sorted
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

	// Clean up and free the stack
	free_stack(&a);
	return (0);
}
