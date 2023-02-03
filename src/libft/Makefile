# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 06:13:39 by kpawlows          #+#    #+#              #
#    Updated: 2023/01/25 17:02:01 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC 		=	gcc
FLAGS	=	-Wall -Werror -Wextra -c
AR 		=	ar -rcs
RM		=	rm -rf
SRC 	= 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c
OBJ		=	$(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC)
	@$(AR) $(NAME) $(OBJ)
	@printf "[libft]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ)
	@printf "[libft]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "[libft]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[libft]$(GREEN) \t re successful $(END)\n"