//
// Created by lain on 4/3/25.
//
#include "background.h"
#include "../tools/tools.h"


void load_background(Game *game) {
    SDL_Surface *background;
    //load
    background = IMG_Load("/home/lain/Desktop/nerding/SDL/LUCK UP/src/assets/grphics/basic/back.png");
    //scale
    background = scaleSurface(background,game->width, game->height);

    // no animation yet





    game->background = background;
}


