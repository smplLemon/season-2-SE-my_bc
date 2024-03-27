CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRC = my_readline.c
TARGET = my_readline

$(TARGET):$(SRC)
	@$(CC) $(CFLAGS) -o $@ $^

.PHONY: fclean

fclean: clean

clean:
	@rm -r $(TARGET)

make re:
	@rm -r $(TARGET)
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run:
	@./$(TARGET)
