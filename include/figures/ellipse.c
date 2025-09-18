#include "common.h"
#define ELLIPSE_B 1
#define ELLIPSE_A 1

// The function that will retrieve the points of the ellipse
float phi(int j, int line, float delta){
    float step = PI/delta;

    if(line){
        return ELLIPSE_B*sinf(step*j);
    }

    return ELLIPSE_A*cosf(step*j);
}

// Draws an epilleptic ellipse over the user window
void draw_ellipse(int rand_val){
    glBegin(GL_POLYGON);

    float step_delta = DRAW_STEPS/2;

    for(int i = 0; i <= DRAW_STEPS; i++){
        glVertex2f(phi(i, 0, step_delta), phi(i, 1, step_delta));
        glColor3f(rand_val % 2, rand_val % 3,  rand_val % 5);
    }
    
    glEnd();
}