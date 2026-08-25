CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = ej19

all: $(TARGET)

$(TARGET): ej19.o
		$(CC) $(CFLAGS) $^ -o $@

ej19.o: ej19.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean