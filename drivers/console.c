#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY ((uint16_t*) 0xB8000)

static size_t cursor_row = 0;
static size_t cursor_col = 0;

static uint16_t make_vga_entry(char c, uint8_t color) {
    return (uint16_t)c | ((uint16_t)color << 8);
}

void console_clear() {
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            VGA_MEMORY[y * VGA_WIDTH + x] = make_vga_entry(' ', 0x07);
        }
    }
    cursor_row = 0;
    cursor_col = 0;
}

void console_put_char(char c) {
    if (c == '\n') {
        cursor_col = 0;
        cursor_row++;
    } else {
        VGA_MEMORY[cursor_row * VGA_WIDTH + cursor_col] = make_vga_entry(c, 0x07);
        cursor_col++;
        if (cursor_col >= VGA_WIDTH) {
            cursor_col = 0;
            cursor_row++;
        }
    }
    if (cursor_row >= VGA_HEIGHT) {
        cursor_row = 0; // simple wrap-around
    }
}
