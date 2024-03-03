/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:32:17 by ccasado-          #+#    #+#             */
/*   Updated: 2024/02/27 12:14:25 by ccasado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

void		ft_putchar_va(char c, int *count);
void		ft_putstr_va(char *str, int *count);
void		ft_putptr(unsigned long ptr, int *count);
void		ft_putnbr_va(int nb, int *count);
void		ft_putnbr_ubase(unsigned int nb, char *base, int *count);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
int			ft_printf(char const *str, ...);
void		flag_manager(char v, va_list args, int *count);
#endif
