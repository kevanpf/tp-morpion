CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = morpion

all: $(TARGET)

$(TARGET): main.c tic-tac-toe.h
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
