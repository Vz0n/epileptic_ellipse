#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <sys/time.h>
#include <SDL2/SDL.h>
#include <math.h>
#define PI 3.141592
#define STEPS 512
#define MAX_VALUE 2

long get_time(){
    struct timeval tm = {0};

    gettimeofday(&tm, NULL);

    return tm.tv_usec;
}

float phi(int j, int line, float delta){
    float step = PI/delta;
    int r = 1;

    if(line){
        return r*sinf(step*j);
    }

    return r*cosf(step*j);
}

int main(int argc, char** argv){

    int this_shit_is_running = 1;

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        puts("uh oh");
        return 1;
    }

    struct SDL_Window *win = SDL_CreateWindow("UWU OWO", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

    if(win == 0){
        printf("Uh oh: %s\n", SDL_GetError());
        return 1;
    }
    
    SDL_GLContext ctx = SDL_GL_CreateContext(win);

    SDL_GL_MakeCurrent(win, ctx);

    // Now do some nasty OpenGL stuff
    GLenum num = glewInit();
    if(num != GLEW_OK){
        printf("uh oh: %s", glewGetErrorString(num));
        return 1;
    }

    while(this_shit_is_running){
        SDL_Event event = {0};

        SDL_GL_SwapWindow(win);
        srand(get_time());

        while(SDL_PollEvent(&event)){
          if(event.type == 256){
              this_shit_is_running = 0;
              break;
          }
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);

        float step_delta = STEPS/MAX_VALUE;

        for(int i = 0; i <= STEPS; i++){
            glVertex3f(phi(i, 0, step_delta), phi(i, 1, step_delta), 0.5f);
            glColor3f(rand() % 2, rand() % 3,  rand() % 4);
        }
    
        glEnd();
        glFlush();
    }

    return 0;
}