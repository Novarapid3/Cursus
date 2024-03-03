/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:50:34 by ccasado-          #+#    #+#             */
/*   Updated: 2024/02/27 12:51:18 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *str);
void	str_filler(char *str, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ptr_killer(char **ptr);
int		char_in_string(char c, char *str);
char	*fill_text(int fd, char *text);
char	*one_last_line(char **line, char **text);
char	*get_next_line(int fd);

#endif
