# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 13:40:37 by ladawi            #+#    #+#              #
#    Updated: 2022/07/27 17:43:16 by ladawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUG = -g3


FILES = main.cpp \



SRC_PATH = $(shell find srcs -type d)
vpath %.cpp $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/, $(FILES:%.cpp=%.o))

INC_F = VectorIterators.hpp RandomAccessIterator.hpp ConstVectorIterators.hpp Ft_iterators.hpp ft_utils.hpp \
	stack.hpp map.hpp node.hpp MapIterator.hpp CoreMapIterator.hpp ConstMapIterator.hpp vector.hpp
	
INC_DIR = includes

INC = $(addprefix $(INC_DIR)/, $(INC_F))
INCLUDES = $(INC)

INC_FLAGS = -I $(INC_DIR)

END = \033[0m
RED = \033[0;91m
YEL = \033[93m
GRE = \033[0;92m
PUR = \033[0;95m
BLU = \033[0;34m
BOLD = \033[1m


all : $(NAME)

$(NAME) : $(OBJ_PATH) $(INC) $(OBJ)
	@echo "$(YEL)Made $(NAME)$(END)"
	@echo "$(PUR)Compiling$(END)"
	@$(CC) $(CFLAGS) $(DEBUG) $(INC_FLAGS) $(OBJ) -o ${NAME}

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) $(HEAD) -c -o $@ $(INC_FLAGS) $<
	@echo "$(GRE)$@$(END)"

print:
	@echo $(OBJ)

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)$(BOLD)Removed *.o in $(OBJ_PATH)$(END)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)$(BOLD)Removed $(NAME) $(END)"

re: fclean all