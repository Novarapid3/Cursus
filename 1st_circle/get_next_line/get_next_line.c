/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:47:22 by ccasado-          #+#    #+#             */
/*   Updated: 2024/02/27 19:34:15 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ptr_killer(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

int	char_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*fill_text(int fd, char *text)
{
	char	*read_result;
	int		bytes;

	bytes = 1;
	read_result = malloc(BUFFER_SIZE + 1);
	if (!read_result)
		return (ptr_killer(&text));
	read_result[0] = '\0';
	while (bytes > 0 && char_in_string('\n', read_result) == -1)
	{
		bytes = read(fd, read_result, BUFFER_SIZE);
		if (bytes == -1)
		{
			ptr_killer(&read_result);
			return (ptr_killer(&text));
		}
		read_result[bytes] = '\0';
		text = ft_strjoin(text, read_result);
	}
	ptr_killer(&read_result);
	return (text);
}

char	*one_last_line(char **line, char **text)
{
	if (*text[0] == '\0')
		return (ptr_killer(text));
	*line = ft_substr(*text, 0, ft_strlen(*text));
	ptr_killer(text);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	text = fill_text(fd, text);
	if (!text)
		return (NULL);
	if (char_in_string('\n', text) != -1)
	{
		line = ft_substr(text, 0, char_in_string('\n', text) + 1);
		if (!line)
			return (ptr_killer(&text));
		tmp = ft_substr(text, char_in_string('\n', text) + 1, ft_strlen(text));
		if (!tmp)
			return (ptr_killer(&line), ptr_killer(&text));
		ptr_killer(&text);
		text = tmp;
	}
	else
		line = one_last_line(&line, &text);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		printf("line [%d]:%s", i, line);
		i++;
		line = get_next_line(fd);
		free(line);
	}
	printf("line [%d]:%s", i, line);
	return (0);
}
