#include "../include/player.h"

void initPlayer(Player *player) {
    player->x = 300;
    player->y = 200;
    player->x_speed = 0;
    player->y_speed = 0;
    player->x_accel = 0;
    player->y_accel = 0.3;// gravity
    player->health = 10;
    player->level = 1; // Initialize level
    player->moveLeft = player->moveRight = player->moveUp = player->moveDown = false;

    player->surface = SDL_CreateRGBSurface(SDL_SWSURFACE, SQUARE_SIZE, SQUARE_SIZE, 32, 0, 0, 0, 0);
    SDL_FillRect(player->surface, NULL, SDL_MapRGB(player->surface->format, 255, 0, 0));
}

void handlePlayerMovement(Player *player, SDL_Event e) {
    bool isKeyDown = (e.type == SDL_KEYDOWN);
    switch (e.key.keysym.sym) {
        case SDLK_q: player->moveLeft = isKeyDown; break;
        case SDLK_d: player->moveRight = isKeyDown; break;
        case SDLK_z: player->moveUp = isKeyDown; break;
        //case SDLK_s: player->moveDown = isKeyDown; break;
    }
}

void updatePlayer(Player *player) {
    // static state
    //player->x_speed = 0;
    //player->y_speed = 0;
    if (player->moveLeft) player->x_speed = - MOVE_SPEED;
    if (player->moveRight) player->x_speed = MOVE_SPEED;
    if (player->moveUp) {
        player->y_speed -= player->y_accel; // fly
        //player->y_speed = -10; // jump

    }
    if (!player->moveUp) {
       player->y_speed += player->y_accel;
    }

    // Update player position
    player->x += player->x_speed;
    player->y += player->y_speed;

    // speed limit (cuz the phisics kinda suck)
    if (player-> y_speed > 7) player->y_speed = 7;
    if (player-> y_speed < -7) player->y_speed = -7;
}

void renderPlayer(SDL_Surface *screen, Player *player) {
    // for now it will just draw a red square but we will change it later
    SDL_Rect rect = { player->x, player->y, SQUARE_SIZE, SQUARE_SIZE };
    SDL_BlitSurface(player->surface, NULL, screen, &rect);
}