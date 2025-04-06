
//
// Created by lain on 4/3/25.
//
#include "game.h"
#include "../tools/tools.h"



void Ini_Game(Game *game) {
    game->height = HEIGHT;
    game->width = WIDTH;
    game->title = "LUCK UP";
    game->state = 1;
    game->quite = 0;
    game->screen = SDL_SetVideoMode(game->width,game->height,32,SDL_SWSURFACE | SDL_RESIZABLE);
    game->main_font = TTF_OpenFont(FREDOKA_PATH,28);



    game->b_purple = IMG_Load(BUTTON_PNG_PATH );


    game->b_yellow = IMG_Load(BUTTON_PNG2_PATH );



}