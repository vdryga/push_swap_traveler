NAME := input_gen
CC := cc

SRCS :=	main.c \
		disorder.c \
		create_stack.c \
		reorganize.c

OBJ_DIR := obj
OBJ := $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDE := -I..

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(INCLUDE) -g -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(INCLUDE) $(OBJ) -g -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
