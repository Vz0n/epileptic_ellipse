#include "figures/rectangle.c"
#include "figures/ellipse.c"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_usage(char* program_name, const fig_function* figures, int fig_count){
    printf("usage: %s <figure>\n", program_name);
    puts("draws a rainbow-flashing figure in a window");
    puts("available figures: ");

    for(int i = 0; i < fig_count; i++){
        printf("- %s\n", figures[i].name);
    }
}

int main(int argc, char** argv){

    const fig_function AVAILABLE_FIGURES[] = {
        {
            "ellipse",
            &draw_ellipse
        },
        {
            "rectangle",
            &draw_rectangle
        }
    };

    int figures_count = sizeof(AVAILABLE_FIGURES)/sizeof(fig_function);

    if(argc < 2){
        print_usage(argv[0], AVAILABLE_FIGURES, figures_count);

        return 1;
    }

    void* selected_function = NULL;
    char* fig = argv[1];

    for(int i = 0; i < figures_count; i++){
        // Remember that strcmp 
        if(!strcmp(fig, AVAILABLE_FIGURES[i].name)){
            selected_function = AVAILABLE_FIGURES[i].f;
        }
    }

    if(!selected_function){
        puts("unknown figure type selected");

        return 1;
    }

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("failed to init sdl: %s", SDL_GetError());

        return 1;
    }

    puts("Press CTRL + C to close the window!");
    return create_window_and_draw(selected_function);
}