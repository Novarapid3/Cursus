# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccasado- <ccasado-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 22:54:42 by ccasado-          #+#    #+#              #
#    Updated: 2024/02/27 12:16:52 by ccasado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------VARS--------------------------------------#

NAME = libftprintf.a

HEADER = ft_printf.h

LIBFT = libft/libft.a

LIBFT_MAKE = Make -C libft 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

#-----------------------------------FILES--------------------------------------#

SOURCE_FILES = ft_printf.c ft_printf_printer.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

PREQ = $(HEADER) $(LIBFT) Makefile

#-----------------------------------TARGET-------------------------------------#

all: makelibs $(NAME)

makelibs: 
	$(LIBFT_MAKE)

$(NAME): $(OBJECT_FILES)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJECT_FILES)

%.o: %.c $(PREQ)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(LIBFT_MAKE) clean
	rm -f $(OBJECT_FILES)

fclean: clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean

.SILENT:
