#include "src/code/game/game.h"
#include "src/code/tools/tools.h"
#include "src/code/Player/player.h"
#include"src/code/Background/background.h"
#include "src/code/game/button.h"



/*
 *to do list  :
 *******************************************************************************************************************************
 *-     manual text render    |                                                                                       done!
 *                            |-> apply                                                                               done!
 *
 *-
 *
 *-     scale button handling   |
 *                              |-> render buttons                                                                     done!
 *                              |-> create buttons :
 *                                  |> manual                                                                          done!
 *                                  |> automation                                                                      done!
 *******************************************Sun Apr 6 02:11:29 AM CET 2025******************************************************
 *
 *-     check if the single button is being pressed
 *-     create a menu
 *-     menu handling
 *-     travel between menus
 *-     create a tree like data structure where each node can point to a menu (menu mapping )
 *-     handle button actions using a current button list
 *-     move to the gameplay
 *-     player mvt
 *-     handle animation
 *-     handle player hit-box and collisions
 *-     handle pixel collision
 *-     handle split screen gameplay
 *******************************************************************************************************************************
 *                                                                                                                  -lain
 */











/*
 *
 **********************************************************
 * * *       T E S T I N G        F I E L D           * * *
 **********************************************************
 *
 */

int test( ) {
    printf("testing ... \n");
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    int width = 600 ,height = 400;
    int quit =0;

    SDL_Surface *screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 10, 10, 10));




    // Text creation
    TTF_Font *font = TTF_OpenFont("../src/assets/font/fredoka-one.one-regular.ttf", 28);
    SDL_Surface *text = TTF_RenderText_Blended(font, "play", (SDL_Color){100, 100, 100});
    SDL_Rect textRect = {(width -text->w)/2  , (height - text->h)/2, text->w, text->h};



    // target surf
    SDL_Surface *green = create_color_surface(300 , 50 , 220,200,200);
    SDL_Rect green_rect = {10,10,green->w,green->h};


    // modification :
    textRect = (SDL_Rect){ green_rect.x + (green_rect.w - textRect.w)/2 , green_rect.y + (green_rect.h - textRect.h)/2 , textRect.w , textRect.h};






    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_BlitSurface(green, NULL, screen, &green_rect);
        SDL_BlitSurface(text, NULL, screen, &textRect);
        SDL_Flip(screen);
    }



    SDL_Quit();
    return 0;
}










int main(int argc, char *argv[]) {

   // obv testing ...
   // return test();




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


    if (IMG_Init(IMG_INIT_PNG)<0) {
        printf("IMG_Init failed: %s\n", IMG_GetError());
        return 1;
    }


    // init game
    Game game;

     Ini_Game(&game);




    // load BG
    load_background(&game);




    // an array of text


    // discovered i3a9a fi C





    //declaire a button
    Button pur,yel;
    pur.txt.writen = "PLAY";    //
    pur.txt.color = (SDL_Color){0,0,0};//
    pur.isHovered = 0;//
    pur.w = 300;//
    pur.h = 200;//
    pur.x = (WIDTH - pur.w)/2 ;//
    pur.y = (HEIGHT - pur.h)/2 ;//
    pur.rect = (SDL_Rect) { pur.x,pur.y,pur.w,pur.h };//
    pur.not_hovered =  scaleSurface(game.b_purple, pur.w, pur.h );//
    pur.hovered = scaleSurface(game.b_yellow, pur.w, pur.h );//



    //pur.hovered = game.b_purple;
    //pur.not_hovered = game.b_yellow;


    // this values where tested manually they only work for my image -lain (the work has to be revisited if another button was chosen)
    pur.b_rect = (SDL_Rect){(pur.x + pur.w/22) , (pur.y + pur.h/2.9), (pur.w - pur.w/15), pur.h/3};//
    // click / text -  surf
    //pur.basic = create_color_surface(pur.b_rect.w , pur.b_rect.h ,161,134,190 );
    pur.basic = create_color_surface(pur.b_rect.w , pur.b_rect.h ,pur.txt.color.r ,pur.txt.color.g ,pur.txt.color.b );//


    // txt surf
    pur.txt.surf = TTF_RenderText_Blended(game.main_font, pur.txt.writen, pur.txt.color);//
    //txt rect
    pur.txt.rect = (SDL_Rect){0, 0, pur.txt.surf->w, pur.txt.surf->h};//


    pur.txt.rect = (SDL_Rect){ pur.b_rect.x + (pur.b_rect.w - pur.txt.rect.w)/2 , pur.b_rect.y + (pur.b_rect.h - pur.txt.rect.h)/2 , pur.txt.rect.w , pur.txt.rect.h};//

    yel = *create_button(&game, (WIDTH - 200 )/2, pur.y + pur.txt.rect.h + 50 ,200 ,200,"exit",(SDL_Color){0,0,0},1);
    yel.isHovered = 1;

    SDL_Event event;
    while(!game.quite ) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game.quite = 1;
            }
        }






        //SDL_BlitSurface(game.background,NULL,game.screen,NULL);
        render_button(&game,pur);
        render_button(&game,yel);






        // basic
        //SDL_BlitSurface(pur.basic,NULL,game.screen,&pur.b_rect);
        // rend  button att
        //SDL_BlitSurface(pur.hovered,NULL,game.screen,&pur.rect);


        //render text :
        //SDL_BlitSurface(pur.text_surface,NULL,game.screen,&pur.b_rect);
        //SDL_BlitSurface(pur.text_surface, NULL, game.screen, &(SDL_Rect){0, 0, 0, 0});


        SDL_Flip(game.screen);
    }



    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}














