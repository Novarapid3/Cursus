/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:43 by ccasado-          #+#    #+#             */
/*   Updated: 2024/02/27 12:51:19 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		s_len;
	char	*str;
	int		min_val;

	s_len = 0;
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	min_val = len * (len <= (s_len - start)) + (s_len - start) * \
			(len > (s_len - start));
	str = (char *)malloc(sizeof(char) * (min_val + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < min_val && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	str_filler(char *str, char *s1, char *s2)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (k < i)
	{
		str[k] = s1[k];
		k++;
	}
	k = 0;
	while (k < j)
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(i + j + 1);
	if (!str)
		return (ptr_killer(&s1));
	str_filler(str, s1, s2);
	ptr_killer(&s1);
	return (str);
}
