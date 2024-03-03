/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:29:21 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/13 18:20:38 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;		

	c1 = s1;
	c2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && c1[i] == c2[i])
		i++;
	if (i == n)
		return (c1[i - 1] - c2[i - 1]);
	else
		return (c1[i] - c2[i]);
}
