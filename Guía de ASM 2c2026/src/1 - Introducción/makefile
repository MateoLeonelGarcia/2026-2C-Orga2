AS := nasm
ASFLAGS := -f elf64 -F DWARF -g -Wall -Wextra -Werror
LD := ld
LDFLAGS := -g
TARGET := HolaMundo

.PHONY: all clean
all: $(TARGET)
HolaMundo.o: HolaMundo.asm
	$(AS) $(ASFLAGS) $<
$(TARGET): HolaMundo.o
	$(LD) $(LDFLAGS) $< -o $@
clean:
	rm -rf *.o $(TARGET)