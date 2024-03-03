/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:33:06 by ccasado-          #+#    #+#             */
/*   Updated: 2024/01/25 19:07:26 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcount(char const *s, char c)
{
	int		delimiter_flag;
	size_t	str_count;
	size_t	i;

	i = 0;
	str_count = 0;
	delimiter_flag = 1;
	while (s[i])
	{
		if (s[i] != c && delimiter_flag == 1)
		{
			str_count++;
			delimiter_flag = 0;
		}
		if (s[i] == c && delimiter_flag == 0)
			delimiter_flag = 1;
		i++;
	}
	return (str_count);
}

static void	ft_free_n(char **array, size_t n)
{
	while (n > 0)
	{
		free(array[n]);
		n--;
	}
	free(array[0]);
	free(array);
}

static char	**ft_make_malloc(char const *s, char c)
{
	char	**array;

	array = (char **)malloc((ft_strcount(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (array);
}

static void	ft_set_vars(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_start;
	char	**array;

	ft_set_vars(&i, &j);
	array = ft_make_malloc(s, c);
	while (i < ft_strcount(s, c) && array && s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		word_start = j;
		while (s[j] && s[j] != c)
			j++;
		array[i] = ft_substr(s, word_start, j - word_start);
		if (!array[i])
		{
			ft_free_n(array, i);
			return (NULL);
		}
		i++;
	}
	if (array)
		array[i] = NULL;
	return (array);
}
