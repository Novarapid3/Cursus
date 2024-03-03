/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:02:03 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/17 12:55:08 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	str_cpy = (char *)malloc(len * sizeof(char) + 1);
	if (!str_cpy)
		return (NULL);
	while (i < len)
	{
		str_cpy[i] = s1[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
