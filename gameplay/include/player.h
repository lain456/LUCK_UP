#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include <stdbool.h>

#define SQUARE_SIZE 50
#define MOVE_SPEED 5

typedef struct {
    //momvements
    int x, y;
    float x_speed, y_speed;
    float x_accel, y_accel;
    //stats
    int health;
    int level; // Add level attribute
    bool moveLeft, moveRight, moveUp, moveDown;

    // animation spritsheet WIP
    SDL_Surface *surface;
    SDL_Surface * flying_to_the_right[4];
    SDL_Surface * flying_to_the_left[4];


    // fight animation WIP

    int player_num;

} Player;

void initPlayer(Player *player);
void handlePlayerMovement(Player *player, SDL_Event e);
void updatePlayer(Player *player);
void renderPlayer(SDL_Surface *screen, Player *player);

#endif // PLAYER_H