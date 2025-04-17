
//
// Created by lain on 4/3/25.
//
#include "game.h"
#include "../tools/tools.h"

void Ini_Game(Game *game) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO | SDL_DOUBLEBUF) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        exit(1);
    }

    if (TTF_Init() < 0) {
        printf("TTF_Init failed: %s\n", TTF_GetError());
        exit(1);
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        printf("Mix_OpenAudio failed: %s\n", Mix_GetError());
        exit(1);
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        printf("IMG_Init failed: %s\n", IMG_GetError());
        exit(1);
    }

    printf("game running..\n");




    game->released_mouse =0;
    game->mouse_pressed =0;
    game->height = HEIGHT;
    game->width = WIDTH;
    game->title = "LUCK UP";
    game->state = 1;
    game->quite = 0;
    game->music_volume = 69 * 128 / 100; // Initial volume
    game->screen = SDL_SetVideoMode(game->width, game->height, 32, SDL_SWSURFACE | SDL_RESIZABLE);
    if (!game->screen) {
        printf("SDL_SetVideoMode failed: %s\n", SDL_GetError());
        exit(1);
    }

    // Load fonts with error checking
    game->mini_font = TTF_OpenFont(FREDOKA_PATH, 20);
    game->main_font = TTF_OpenFont(FREDOKA_PATH, 28);
    game->mid_font = TTF_OpenFont(FREDOKA_PATH, 30);
    game->big_main_font = TTF_OpenFont(FREDOKA_PATH, 45);
    if (!game->mini_font || !game->main_font || !game->mid_font || !game->big_main_font) {
        printf("Failed to load fonts: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    game->x_button_size = 200;
    game->y_button_size = 100;

    // Load button images
    game->b_purple = IMG_Load(BUTTON_PNG_PATH);
    game->b_yellow = IMG_Load(BUTTON_PNG2_PATH);
    if (!game->b_purple || !game->b_yellow) {
        printf("Failed to load button images: %s\n", IMG_GetError());
        if (game->b_purple) SDL_FreeSurface(game->b_purple);
        if (game->b_yellow) SDL_FreeSurface(game->b_yellow);
        TTF_CloseFont(game->mini_font);
        TTF_CloseFont(game->main_font);
        TTF_CloseFont(game->mid_font);
        TTF_CloseFont(game->big_main_font);
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    game->current_menu = NULL;

    // Slider config
    game->slider_bg_color = (SDL_Color){91, 29, 191};
    game->slider_fill_color = (SDL_Color){250, 250, 150};
    game->slider_bg = NULL;
    game->slider_fill = NULL;
    game->b_slider = NULL;
    game->x_slider_size = 250;
    game->y_slider_size = 20;
}





