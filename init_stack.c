/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:03:12 by edouard           #+#    #+#             */
/*   Updated: 2024/01/10 22:27:58 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack_a(t_stack **a, char **argv)
{
	long num;
	int i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			exit_error(a);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN || check_duplicates(*a, num))
			exit_error(a);
		add_node(a, num);
		i++;
	}
}

void add_node_append(t_stack **a, int num)
{
	t_stack *new;
	t_stack *tmp;

	new = ft_calloc(sizeof(t_stack), 1);
	if (!new)
		exit_error(*a);
	new->value = num;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		tmp = find_last(*a);
		tmp->next = new;
		new->prev = tmp;
	}
}
