CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRC = source/*.c bc.c
TARGET = my_bc

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ 

.PHONY :
	fclean

fclean : clean

clean:
	@rm -rf $(TARGET) 

make re:
	@rm -rf $(TARGET) 
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) 
