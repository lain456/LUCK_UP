#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "src/code/game/game.h"
#include "src/code/tools/tools.h"
#include "src/code/Player/player.h"
#include"src/code/Background/background.h"









int main(int argc, char *argv[]) {
    printf("game running..\n");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_VIDEO | SDL_DOUBLEBUF )<0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init()<0) {
        printf("TTF_Init failed: %s\n", TTF_GetError());
        return 1;
    }

    if (Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096)<0) {
        printf("Mix_OpenAudio failed: %s\n", Mix_GetError());
        return 1;
    }

    /*
    if (IMG_Init(IMG_INIT_PNG)<0) {
        printf("IMG_Init failed: %s\n", IMG_GetError());
        return 1;
    }
*/


    Game game;
    game.height = HEIGHT;
    game.width = WIDTH;
    game.title = "LUCK UP";
    game.state = 1;
    game.quite = 0;
    game.screen = SDL_SetVideoMode(game.width,game.height,32,SDL_SWSURFACE | SDL_RESIZABLE);


    // this is how you load images
    SDL_Surface *bird = IMG_Load("../src/assets/grphics/characters/bird/flying to the left/b0.png");

    // scale its size:
    bird = scaleSurface(bird, bird->w /3, bird->h/3 );


    // load BG
    load_background(&game);













    // make a white surf
    SDL_Surface *green = create_color_surface(game.width,game.height,225,225,225);

    //printf("%s\n",game.title);
    SDL_Event event;
    while(!game.quite ) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game.quite = 1;
            }
        }


        SDL_BlitSurface(game.background,NULL,game.screen,NULL);
        SDL_Flip(game.screen);



    }









    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}


