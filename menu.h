#ifndef MENU_H
#define MENU_H

void draw_option(int row, const char *text, int is_hovered);
void display_menu(int current_selection);
void handle_input(int *current_selection);

#endif // MENU_H
