CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = ej18

all: $(TARGET)

$(TARGET): ej18.o
		$(CC) $(CFLAGS) $^ -o $@

ej18.o: ej18.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean