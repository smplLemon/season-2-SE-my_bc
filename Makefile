CC = gcc
CFLAGS = -Wall -Wextra -Werror - g3 -fsanitize=address
SRC = my_bsq.c
TARGET = my_bsq* c/my_string.c

$(TARGET): $(SRC)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY:fclean

fclean:
	@rm -rf $(TARGET)
