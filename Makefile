# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 05:15:37 by kpawlows          #+#    #+#              #
#    Updated: 2023/03/02 01:22:53 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRC_DIR	=	src/
OBJ_DIR	=	obj/
CC 		=	gcc
FLAGS	=	#-Wall -Werror -Wextra
AR 		=	ar -rcs
LINK 	=	$(CC) $(FLAGS)
RM		=	rm -f
SRC 	= 	$(SRC_DIR)arr_utils.c \
			$(SRC_DIR)do.c \
			$(SRC_DIR)find_1.c \
			$(SRC_DIR)find_2.c \
			$(SRC_DIR)input_utils.c \
			$(SRC_DIR)lst_utils_1.c \
			$(SRC_DIR)lst_utils_2.c \
			$(SRC_DIR)main.c \
			$(SRC_DIR)push_swap.c \
			$(SRC_DIR)sort_utils.c \
			$(SRC_DIR)sort.c
OBJ		=	$(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME) link

$(NAME): $(SRC) 
	@$(MAKE) -C src/libft
	@$(CC) $(FLAGS) -c $(SRC)
	@mv *.o $(SRC_DIR)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	
link : $(NAME) $(OBJ)
	@$(CC) $(OBJ) src/libft/libft.a -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@$(RM) $(OBJ)
	@cd src/libft && $(MAKE) clean 
	@$(RM) /src/libft/libft.a
	@printf "[$(NAME)]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@$(RM) $(NAME)
	@cd src/libft && $(MAKE) fclean
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"
