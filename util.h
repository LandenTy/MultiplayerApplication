#ifndef UTIL_H
#define UTIL_H

#define LINES 250
#define COLUMNS 250
#define OPTION_COUNT 2  // Add this line to define OPTION_COUNT

void set_color(int color);
void hide_cursor();
void clear_middle_area();
void randomize_screen_effect();

extern const char *options[OPTION_COUNT];

#endif // UTIL_H
