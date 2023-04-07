# EXECUTABLE
NAME		=	cpp05_ex00

# CONFIGURATION
CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98

# COLOR CODES
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
RED			=	\033[31m

# DIRECTORIES
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/
HDR_DIR		=	includes/

# FILES
SRC_FILES	=	main.cpp Bureaucrat.cpp
				
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

HDR_FILES	=	Bureaucrat.hpp

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
HDR			=	$(addprefix $(HDR_DIR), $(HDR_FILES))

# RULES
all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	@echo "$(YELLOW)Compiling..[$(NAME)]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished compiling..$(NAME)$(RESET)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(HDR)
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling..[$@]$(RESET)"
	@$(CC) $(CFLAGS) -I $(HDR_DIR) -o $@ -c $<

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(RED)Deleting all object files..$(RESET)"; else \
	echo "No object files to delete.."; \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(RED)Deleting $(NAME)$(RESET)"; else \
	echo "$(RED)No executable to delete.$(RESET)"; \
	fi;

re: fclean all

.PHONY: all clean fclean re

