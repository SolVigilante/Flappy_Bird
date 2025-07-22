#include <ncurses.h>
#include <sys/time.h>  // gettimeofday
#include "bird.h"
#include "bird_graphics.h"
#include "flying_logic.h"

static void bird_update(bird_t* bird, char c);
static void flying_physics(bird_t * bird);

long long current_time_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}

static void bird_update(bird_t* bird, char c){
    switch (c) {
        case ' ': 
            if(bird->velocity > 10.0f){ // If the bird is already flying up, it doesn't do anything
                bird->velocity = -GRAVITY/10.0f; // Sets the velocity to a negative value to make the bird fly up
                bird->acceleration = 0.0f; // It sets the acceleration to 0, so it doesn't fall immediately
                break;
            }else{
                 bird->acceleration += GRAVITY*0.1f; //It adds a portion of the gravity to the acceleration everio 0.1 seconds 
                break;
            }
            
        case ERR:
            bird->acceleration += GRAVITY*0.1f; //It adds a portion of the gravity to the acceleration everio 0.1 seconds 
            break;
        default:
            break; //ignores any other input
    }
}

static void flying_physics(bird_t * bird){
    if(bird->acceleration > GRAVITY){
            bird->acceleration = GRAVITY; // Limit the acceleration to the gravity
        }
        bird->velocity += bird->acceleration*0.1f; //Velocity in functtion of acceleration
        bird->bird_y += bird->velocity * 0.1f; //position in function of velocity
}

long long game_start(char c, long long last_gravity_time, bird_t* bird) { 
    long long now = current_time_ms(); //stores the current time in milliseconds
    clear();
    if (now - last_gravity_time >= 50){ // Every 50ms, we update the bird's physics
        flying_physics(bird); // Updates the bird's physics
        last_gravity_time = now; 
    }
    bird_update(bird, c); // Updates the bird's state based on input
    if(bird->velocity < 0.0f){
        draw_fbird(bird); // If the bird is flying, we draw the flying wings
    }else{
        draw_dbird(bird); // If the bird is descending, we draw the descending wings
    }
    refresh(); // Refreshes the screen to show the updated graphics
    return last_gravity_time; // Returns the last gravity time to be used in the next iteration
}