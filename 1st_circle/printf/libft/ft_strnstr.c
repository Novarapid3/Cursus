/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:45:06 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/19 01:37:35 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (nd[0] == '\0')
		return ((char *)hs);
	while (i < len && hs[i])
	{
		j = 0;
		while (nd[j] && hs[i + j] && nd[j] == hs[i + j] && (i + j) < len)
			j++;
		if (nd[j] == '\0')
			return ((char *)&hs[i]);
		i++;
	}
	return (NULL);
}
