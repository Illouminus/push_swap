/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaillot <ebaillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:05:21 by ebaillot          #+#    #+#             */
/*   Updated: 2024/02/15 17:02:16 by ebaillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_print_pointer(void *ptr);

int	ft_putnbr(int nb);

int	ft_putnbr_base(unsigned long nbr, char *base);

#endif