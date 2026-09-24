CC = gcc
CFLAGS ?= -std=c2x -O2 -Wall -Wextra -I.
TARGET = test_dynamic_array.out

.PHONY: test clean

all: test

test: $(TARGET)
	./$(TARGET)

$(TARGET): tests/test_dynamic_array.c DynamicArray.h DynamicArray.def
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)
