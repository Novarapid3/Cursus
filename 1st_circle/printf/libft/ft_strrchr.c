/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:55:48 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/18 23:02:49 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}
