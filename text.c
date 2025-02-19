#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "text.h"
#include "util.h"

void display_text_in_middle(const char *text) {
    int mid_row = LINES / 2;
    int mid_col = COLUMNS / 2 - strlen(text) / 2;
    printf("\033[%d;%dH%s", mid_row, mid_col, text);
}

void type_out_text(const char *text) {
    int i = 0;
    while (text[i] != '\0') {
        char current_text[i + 1];
        strncpy(current_text, text, i + 1);
        current_text[i + 1] = '\0';

        clear_middle_area();
        display_text_in_middle(current_text);

        Sleep(100);
        i++;
    }
}
