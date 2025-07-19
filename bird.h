#ifndef BIRD_H
#define BIRD_H
#define GRAVITY 100.0f //Gavity constant
typedef struct{
    char * fwings; //String of flying wings
    char * dwings; // string of descending wings
    char * body; // String of the body
}bird_shape_t;
typedef struct{
    bird_shape_t shape;
    int bird_x; //X position of the bird
    int bird_y; //Y position of the bird
    float velocity; //Velocitty of the bird
    float acceleration; //Acceleration of the bird
}bird_t;
#endif // BIRD_H

