CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = cat.c file.c
OBJ = $(SRC:.c=.o)
BIN_DIR = bin
TARGET = $(BIN_DIR)/cat

all: $(TARGET)

$(TARGET): $(BIN_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test:
	tests/run-tests.sh

clean:
	rm -rf $(OBJ) $(TARGET) $(BIN_DIR)

.PHONY:
	all clean
