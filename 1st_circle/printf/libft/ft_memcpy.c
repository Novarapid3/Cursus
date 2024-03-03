/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:19 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/21 13:45:52 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	return (ft_memmove(dst, src, n));
}
// size_t	i;
// i = 0;
// while (i < n)
// {
// 	((char *)dst)[i] = ((char *)src)[i];
// 	i++;
// }
// return (dst);