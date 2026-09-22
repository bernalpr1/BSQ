NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR = srcs
INC_DIR = includes

HEADER = $(INC_DIR)/bsq.h

SRC = $(SRC_DIR)/algo.c \
      $(SRC_DIR)/grid_init.c \
      $(SRC_DIR)/parser.c \
      $(SRC_DIR)/parser_helper.c \
      $(SRC_DIR)/translate.c \
      $(SRC_DIR)/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
