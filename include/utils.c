#include "utils.h"

long get_time(){
    struct timeval tm = {0};

    gettimeofday(&tm, NULL);

    return tm.tv_usec;
}

int create_window_and_draw(void* drawer_function){
    void (*r)(int) = drawer_function; 
    SDL_Window* win =  SDL_CreateWindow("rainbow figure", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        WINDOWW, 
        WINDOWH, 
        SDL_WINDOW_OPENGL);
    
    if(!win){
        printf("error creating window: %s", SDL_GetError());

        return 1;
    }

    SDL_GL_CreateContext(win);
    GLenum result = glewInit();

    if(result != GLEW_OK){
        printf("error initializing gl: %s", glewGetErrorString(result));

        return 1;
    }

    // Clear color buffer bits and put the screen in white
    glClear(GL_COLOR_BUFFER_BIT);

    while(1){
        SDL_Event ev = {0};

        srand(get_time());
        SDL_GL_SwapWindow(win);

        while(SDL_PollEvent(&ev)){
            // The program was marked to exit
            if(ev.type == 256){

                SDL_DestroyWindow(win);
                SDL_Quit();
                return 0;
            }
        }

        r(rand());
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}