# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccasado- <ccasado-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 23:12:28 by ccasado-          #+#    #+#              #
#    Updated: 2024/02/13 23:19:42 by ccasado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#------------------------------------VARS--------------------------------------#


NAME = libft.a

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

SOURCE_FILES = ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_memchr.c\
		ft_memcpy.c ft_memset.c ft_strlcat.c ft_strlen.c ft_strnstr.c\
		ft_tolower.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_memcmp.c ft_memmove.c ft_strchr.c ft_strlcpy.c ft_strncmp.c\
		ft_strrchr.c ft_toupper.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
		
BONUS_SOURCE = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
		
OBJECT_FILES = $(SOURCE_FILES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCE:.c=.o)

PREQ = $(HEADER) Makefile

TICK = $(shell echo "\xE2\x9C\x94")



#----------------------------------NORMS----------------------------------------#


all: $(NAME)

ifndef BONUS
$(NAME): $(OBJECT_FILES)
	@$(AR) $(NAME) $(OBJECT_FILES)
	@echo "Object files added to $(NAME)."
else
$(NAME): $(OBJECT_FILES) $(BONUS_OBJECTS)
	@$(AR) $(NAME) $(OBJECT_FILES) $(BONUS_OBJECTS)
	@echo "Bonus object files added to $(NAME)."
endif

%.o: %.c $(PREQ)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[o]Compiling $@"
	@printf "\r[$(TICK)]$@ compiled!\n"

bonus:
	@make BONUS=1 --no-print-directory

clean:
	@rm -f $(OBJECT_FILES)
	@rm -f $(BONUS_OBJECTS)
	@echo "object files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."
	
re: fclean all

.PHONY: all clean fclean re bonus
