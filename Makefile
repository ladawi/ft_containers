# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 13:40:37 by ladawi            #+#    #+#              #
#    Updated: 2022/05/30 14:03:34 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers
CC = c++
HEAD = -Iincludes
CFLAGS = -Wall -Wextra -Werror $(DEBUG)
# DEBUG = -g3


FILES = main.cpp \


SRC_PATH = $(shell find srcs -type d)
vpath %.cpp $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/, $(FILES:%.cpp=%.o))

END = \033[0m
RED = \033[0;91m
YEL = \033[93m
GRE = \033[0;92m
PUR = \033[0;95m
BLU = \033[0;34m
BOLD = \033[1m


all : $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ) ./includes/test.hpp
	@echo "$(YEL)Made $(NAME)$(END)"
	@echo "$(PUR)Compiling$(END)"
	@$(CC) $(CFLAGS) $(HEAD) $(OBJ) -o ${NAME}

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.cpp
	@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
	@echo "$(GRE)$@$(END)"

print:
	@echo $(OBJ)

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)$(BOLD)Removed *.o in $(OBJ_PATH)$(END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"

re: fclean all