/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:59:41 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/19 21:59:36 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_num_len(int n)
{
	int	num_len;

	num_len = 0;
	while (n >= 10)
	{
		n = n / 10;
		num_len++;
	}
	num_len = num_len + 1;
	return (num_len);
}

char	*ft_itoa(int n)
{
	int		num_len;
	char	*str;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n < 0;
	if (sign)
		n = -n;
	num_len = ft_get_num_len(n) + sign;
	str = (char *) malloc(sizeof(char) * (num_len + 1));
	if (!str)
		return (NULL);
	str[num_len] = '\0';
	num_len--;
	while (num_len >= 0)
	{
		str[num_len] = n % 10 + '0';
		n = n / 10;
		num_len--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
