CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2 -ffreestanding -nostdlib -nostartfiles
LDFLAGS = -T linker.ld

ARCH_DIR = arch
BOOT_DIR = boot
DRIVERS_DIR = drivers
FS_DIR = fs
INCLUDE_DIR = include
KERNEL_DIR = kernel
LIB_DIR = lib

SRCS = $(wildcard $(KERNEL_DIR)/*.c) $(wildcard $(LIB_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: kernel.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel.bin: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o kernel.bin

clean:
	rm -f $(OBJS) kernel.bin

.PHONY: all clean
