/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:17:55 by ebaillot          #+#    #+#             */
/*   Updated: 2024/01/03 13:40:10 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		return (ft_putstr("(null)"));
	}
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
