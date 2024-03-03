/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:53:40 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/20 21:50:09 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (char_is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	if (end > 0)
	{
		while (char_is_in_set(s1[end - 1], set) && end > 0)
			end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = find_start(s1, set);
	j = find_end(s1, set);
	if (j > i)
	{
		str = (char *)malloc(j - i + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[i], j - i + 1);
	}
	else
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}
