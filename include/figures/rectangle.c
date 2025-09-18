#include "common.h"

// Draws a rectangle on the user's screen
void draw_rectangle(int rand_val){
    glRectf(-1, -1, 1, 1);
    glColor3f(rand_val % 2, rand_val % 3, rand_val % 5);
}