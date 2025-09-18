#include <time.h>
#include <sys/time.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#define WINDOWW 600
#define WINDOWH 600

// Represents a figure drawer function
typedef struct {
    char* name;
    void* f;
} fig_function;

// Gets the actual time in microseconds
long get_time();

// Creates a SDL OpenGL window and draws a figure. The params are:
// - drawer_function: Pointer to the function that will draw the figure
int create_window_and_draw(void* drawer_function);
