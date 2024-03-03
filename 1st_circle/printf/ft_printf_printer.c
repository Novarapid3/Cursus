/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:09:03 by ccasado-          #+#    #+#             */
/*   Updated: 2024/02/27 12:28:12 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_va(char c, int *count)
{
	int	error_check;

	if (*count != -1)
	{
		error_check = write(1, &c, 1);
		if (error_check == -1)
			*count = -1;
		else
			*count = *count + 1;
	}
}

void	ft_putstr_va(char *str, int *count)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr_va("(null)", count);
		return ;
	}
	i = 0;
	while (str[i] && *count != -1)
	{
		ft_putchar_va((char)str[i], count);
		i++;
	}
}

void	ft_putptr(unsigned long ptr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr > 15)
		ft_putptr(ptr / 16, count);
	ft_putchar_va(base[ptr % 16], count);
}

void	ft_putnbr_ubase(unsigned int nb, char *base, int *count)
{
	int				c;
	unsigned int	base_len;

	base_len = (unsigned int)ft_strlen(base);
	if (nb < base_len)
		ft_putchar_va(base[nb], count);
	else
	{
		c = base[nb % base_len];
		ft_putnbr_ubase(nb / base_len, base, count);
		ft_putchar_va(c, count);
	}
}

void	ft_putnbr_va(int nb, int *count)
{
	int	c;

	if (nb == -2147483648)
	{
		ft_putstr_va("-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_va('-', count);
	}
	if (nb < 10)
		ft_putchar_va(nb + '0', count);
	else
	{
		c = nb % 10 + '0';
		ft_putnbr_va(nb / 10, count);
		ft_putchar_va(c, count);
	}
}
