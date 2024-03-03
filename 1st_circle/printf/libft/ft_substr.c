/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:42:35 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/29 23:14:39 by ccasado-         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	s_len = ft_strlen(s);
	if (start >= s_len)
		str = (char *)malloc(sizeof(char));
	else
		str = (char *)malloc(sizeof(char) \
			* (ft_st_min(len, s_len - start) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_st_min(len, s_len - start) && s[i] && start < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
