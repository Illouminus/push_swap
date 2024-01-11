/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:26:42 by edouard           #+#    #+#             */
/*   Updated: 2024/01/11 09:47:35 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a)
{
	t_stack *big_node;

	big_node = find_biggest(*a);

	if (big_node == *a)
		ra(a, false);
	else if ((**a).next == big_node)
		rra(a, false);
	else
		sa(a, false);
}