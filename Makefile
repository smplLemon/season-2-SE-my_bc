CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRC = my_bc* c/my_string.c
TARGET = my_bc

$(TARGET): $(SRC)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY: fclean

fclean: clean

clean:
	@rm -rf $(TARGET)

make re:
	@rm -rf $(TARGET)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
