#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "menu.h"
#include "text.h"
#include "util.h"  // Include util.h here to access OPTION_COUNT

const char *options[OPTION_COUNT] = {"Host", "Join"};

int main() {
    srand((unsigned int)time(NULL));
    system("cls");
    hide_cursor();  

    set_color(1);
    type_out_text("Welcome Back...");
    clear_middle_area();

    int current_selection = 0;

    while (1) {
        printf("\033[s");  // Save cursor position
        printf("\033[H");  // Reset cursor to top-left

        clear_middle_area();

        display_menu(current_selection);
        randomize_screen_effect();

        printf("\033[u");  // Restore cursor position

        handle_input(&current_selection);

        Sleep(50);
        fflush(stdout);
    }

    return 0;
}
