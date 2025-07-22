#ifndef PIPES_GRAPHIC_H
#define PIPES_GRAPHIC_H
#include "../pipe.h"
void draw_pipes(pipe_t *pipe);// Draw a pipe on the screen at its current position
void erase_pipes(pipe_t *pipe);// Erase the pipe from the screen by replacing it with spaces
#endif // PIPES_GRAPHIC_H