#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

void set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (color == 1) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    } else {
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    }
}

void hide_cursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void clear_middle_area() {
    int mid_start_row = LINES / 4;
    int mid_end_row = 3 * LINES / 4;
    int mid_start_col = COLUMNS / 4;
    int mid_end_col = 3 * COLUMNS / 4;

    for (int i = mid_start_row; i < mid_end_row; i++) {
        for (int j = mid_start_col; j < mid_end_col; j++) {
            printf("\033[%d;%dH ", i, j);
        }
    }
}

void randomize_screen_effect() {
    static int a[COLUMNS] = {0};

    for (int i = 0; i < LINES; i++) {
        int c = rand() % COLUMNS;
        int r = rand() % LINES;
        char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%^&*()";
        char letter = letters[rand() % (sizeof(letters) - 1)];

        a[c] = a[c] + 1;
        if (a[c] > LINES) {
            a[c] = 0;
        }

        printf("\033[%d;%dH\033[32m%c\033[0m", a[c], c, letter);
    }
}
