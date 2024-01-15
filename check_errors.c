/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:11:31 by edouard           #+#    #+#             */
/*   Updated: 2024/01/15 16:07:38 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if the string is a number and check the syb
int error_syntax(char *str)
{
	if (!(*str == '-' || *str == '+') && !ft_isdigit(*str))
		{
		printf("HERE");	
return (1);
		}
		
	while (*++str)
	{
		if (!ft_isdigit(*str))
			return (1);
	}
	return (0);
}

// check if next number is the same as the previous one
int check_duplicates(t_stack *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

// free stack if we have an error
void free_stack(t_stack *a)
{
	t_stack *tmp;

	if (!a)
		return;
	while (a) // Iterate as long as there are nodes in the stack
	{
		tmp = a->next; // Save the pointer to the next node
		free(a);			// Free the current node
		a = tmp;			// Move to the next node
	}
}

void exit_error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(1);
}