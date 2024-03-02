CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
TARGET = my_bsq
SRC = my_bsq* c/my_string.c c/map.c

$(TARGET): $(SRC)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY: fclean

fclean:
	@rm -rf $(TARGET)
