CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = ej17

all: $(TARGET)

$(TARGET): ej17.o
		$(CC) $(CFLAGS) $^ -o $@

ej17.o: ej17.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean