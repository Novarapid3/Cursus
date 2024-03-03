/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:19:08 by ccasado-          #+#    #+#             */
/*   Updated: 2024/02/27 12:28:18 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_manager(char v, va_list args, int *count)
{
	if (v == 'c')
		ft_putchar_va(va_arg(args, int), count);
	else if (v == 's')
		ft_putstr_va(va_arg(args, char *), count);
	else if (v == 'p')
	{
		ft_putstr_va("0x", count);
		ft_putptr(va_arg(args, unsigned long), count);
	}
	else if (v == 'd' || v == 'i')
		ft_putnbr_va(va_arg(args, int), count);
	else if (v == 'u')
		ft_putnbr_ubase(va_arg(args, unsigned int), "0123456789", count);
	else if (v == 'x')
		ft_putnbr_ubase(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (v == 'X')
		ft_putnbr_ubase(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (v == '%')
		ft_putchar_va('%', count);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	int		str_pos;
	va_list	args;

	va_start(args, str);
	count = 0;
	str_pos = 0;
	while (str[str_pos] && count != -1)
	{
		if (str[str_pos] == '%')
		{
			flag_manager(str[str_pos + 1], args, &count);
			str_pos = str_pos + 1;
		}
		else
			ft_putchar_va(str[str_pos], &count);
		str_pos = str_pos + 1;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	ft_printf("%s1234", "hola");
}*/
