# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 13:46:39 by lannur-s          #+#    #+#              #
#    Updated: 2024/06/17 13:46:39 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf
INCLUDE = -I./include
SRC_DIR = src

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

SRC =  main.cpp \
		Fixed.cpp

OBJ_DIR= obj

all: $(OBJ_DIR) $(NAME)
	@echo "${GREEN}Makefile finished successfully!${NC} Run '${YELLOW}${NAME}'${NC}to execute."

$(OBJ_DIR):
	mkdir -p obj

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

