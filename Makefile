NAME = asciinator
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = src/main.cpp
OBJ_DIR = obj
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

# color codes
RED = \033[31m
GREEN = \033[32m
MAGENTA = \033[35m
RESET = \033[0m

SHELL := /bin/bash

# OpenCV installation commands (for Ubuntu)
INSTALL_OPENCV = sudo apt-get install libopencv-dev
REMOVE_OPENCV = sudo apt-get remove --purge libopencv-dev

all: $(NAME)

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ echo -ne "$(MAGENTA)Making $(NAME)"
	@ ( \
		trap 'echo -e "$(RED)Interrupted by user $(RESET)"; exit 1' INT; \
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) & \
		PID=$$!; \
		while kill -0 $$PID 2>/dev/null; do \
			echo -n "."; \
			sleep 0.4; \
			echo -n "."; \
			sleep 0.6; \
			echo -n "."; \
			sleep 0.4; \
		done; \
		wait $$PID; \
	)
	@ echo -ne "\n$(GREEN)Done!$(RED)\n"

# Custom rule to ensure CC is used for compiling .cpp to .o and store in obj directory
$(OBJ_DIR)/%.o: ./src/%.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

install_opencv:
	@ echo -e "$(MAGENTA)Installing OpenCV...$(RESET)"
	@ $(INSTALL_OPENCV)

rm_opencv:
	@ echo -e "$(RED)Removing OpenCV...$(RESET)"
	@ $(REMOVE_OPENCV)

clean:
	@ echo -e "$(RED)Removing $(OBJ_DIR) $(RESET)"
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ echo -e "$(RED)Removing $(NAME) $(RESET)"
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re install_opencv rm_opencv
