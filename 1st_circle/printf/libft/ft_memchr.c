/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:08:32 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/13 16:12:31 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s_cpy;

	s_cpy = s;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == (unsigned char)c)
			return ((void *)&s_cpy[i]);
		i++;
	}
	return (NULL);
}
