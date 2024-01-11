/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:08:02 by edouard           #+#    #+#             */
/*   Updated: 2024/01/03 13:35:26 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long	ptr_val;
	int				count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr_val = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_base(ptr_val, "0123456789abcdef");
	return (count);
}
