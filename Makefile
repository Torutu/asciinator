NAME = asciinator
CC = c++
OPENCV_CFLAGS = `pkg-config --cflags opencv4`
OPENCV_LIBS = `pkg-config --libs opencv4`

CFLAGS = -Wall -Wextra -Werror -std=c++11 $(OPENCV_CFLAGS)
LDFLAGS = $(OPENCV_LIBS)

SRC = src/main.cpp
OBJ_DIR = obj
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

# Color codes
RED = \033[31m
GREEN = \033[32m
MAGENTA = \033[35m
RESET = \033[0m

SHELL := /bin/bash

all: $(NAME)

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ echo -ne "$(MAGENTA)Making $(NAME)"
	@ ( \
		trap 'echo -e "$(RED)Interrupted by user $(RESET)"; exit 1' INT; \
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) & \
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

# Correct rule for compiling .cpp to .o
$(OBJ_DIR)/%.o: src/%.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

install_opencv:
	@ echo -e "$(MAGENTA)Installing OpenCV...$(RESET)"
	@ sudo apt-get install libopencv-dev

rm_opencv:
	@ echo -e "$(RED)Removing OpenCV...$(RESET)"
	@ sudo apt-get remove --purge libopencv-dev

clean:
	@ echo -e "$(RED)Removing $(OBJ_DIR) $(RESET)"
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ echo -e "$(RED)Removing $(NAME) $(RESET)"
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re install_opencv rm_opencv
