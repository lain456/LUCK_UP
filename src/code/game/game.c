
//
// Created by lain on 4/3/25.
//
#include "game.h"
#include "../tools/tools.h"



void Ini_Game(Game *game) {


    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO | SDL_DOUBLEBUF )<0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());

    }

    if (TTF_Init()<0) {
        printf("TTF_Init failed: %s\n", TTF_GetError());

    }

    if (Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096)<0) {
        printf("Mix_OpenAudio failed: %s\n", Mix_GetError());

    }


    if (IMG_Init(IMG_INIT_PNG)<0) {
        printf("IMG_Init failed: %s\n", IMG_GetError());

    }

    printf("game running..\n");



    game->height = HEIGHT;
    game->width = WIDTH;
    game->title = "LUCK UP";
    game->state = 1;
    game->quite = 0;
    game->screen = SDL_SetVideoMode(game->width,game->height,32,SDL_SWSURFACE | SDL_RESIZABLE);

    game->main_font = TTF_OpenFont(FREDOKA_PATH,28);
    game->big_main_font = TTF_OpenFont(FREDOKA_PATH,30);
    game->big_main_font = TTF_OpenFont(FREDOKA_PATH,45);
    game->x_button_size = 200;
    game->y_button_size = 100;



    game->b_purple = IMG_Load(BUTTON_PNG_PATH );


    game->b_yellow = IMG_Load(BUTTON_PNG2_PATH );


    game->current_menu = NULL;



}










