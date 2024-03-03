/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:19:32 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/16 13:25:44 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_st_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	result = ft_strlen(src) + ft_st_min(dstsize, ft_strlen(dst));
	i = 0;
	j = 0;
	if (dstsize != 0)
	{
		while (dst[i])
			i++;
		while (src[j] && i + j < (dstsize - 1))
		{
			dst[i + j] = src [j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (result);
}
