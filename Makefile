CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = main_test.c linked_list.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = linked_list

# Default target
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: 
	./$(EXEC)

valgrind:
	valgrind ./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
