#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "menu.h" 
#include "util.h"

#define OPTION_COUNT 2
extern const char *options[OPTION_COUNT];

void draw_option(int row, const char *text, int is_hovered) {
    int mid_col = COLUMNS / 2 - strlen(text) / 2;
    printf("\033[%d;%dH", row, mid_col); // Move to correct row

    if (is_hovered) {
        printf("\033[4m\033[32m%s\033[0m", text);  // Underlined green text
    } else {
        printf("\033[32m%s\033[0m", text); // Normal green text
    }
}

void display_menu(int current_selection) {
    clear_middle_area();
    for (int i = 0; i < OPTION_COUNT; i++) {
        draw_option(LINES / 2 + i, options[i], i == current_selection);
    }
}

void handle_input(int *current_selection) {
    if (_kbhit()) {
        int ch = _getch();

        if (ch == '\r') {  
            clear_middle_area();
            if (*current_selection == 0) {
                type_out_text("You selected Host...");
            } else if (*current_selection == 1) {
                type_out_text("You selected Join...");
            }
        }
        else if (ch == 0 || ch == 224) {  // Arrow keys
            ch = _getch();
            if (ch == 72) {  // Up arrow
                *current_selection = 0;  // Lock to "Host"
            } else if (ch == 80) {  // Down arrow
                *current_selection = 1;  // Lock to "Join"
            }
        }
    }
}
