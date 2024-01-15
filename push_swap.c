/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:47:48 by edouard           #+#    #+#             */
/*   Updated: 2024/01/15 16:24:52 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Функция для печати стека
void print_stack(t_stack *stack)
{
    if (!stack)
    {
        printf("Стек пуст.\n");
        return;
    }
    printf("Стек содержит:\n");
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}


int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	
	if (argc < 2 || !argv[1][0])
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	init_stack_a(&a, argv + 1);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	print_stack(a);
	return (0);
}