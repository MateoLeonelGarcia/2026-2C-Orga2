CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = ej6

all: $(TARGET)

$(TARGET): ej6.o
		$(CC) $(CFLAGS) $^ -o $@

ej3.o: ej6.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean