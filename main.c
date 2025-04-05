#include "src/code/game/game.h"
#include "src/code/tools/tools.h"
#include "src/code/Player/player.h"
#include"src/code/Background/background.h"
#include "src/code/game/button.h"



/*
 *to do list :
 *******************************************************************************************************************************
 *-     manual text render
 *-     check if the single button is being pressed
 *-     scale button handling
 *-     create a menu
 *-     menu handling
 *-     travel between menus
 *-     create a tree like data structure where each node can point to a menu (menu mapping )
 *-     handle button actions using a current button list
 *-     move to the gameplay
 *-     handle animation
 *-     handle player hit-box and collisions
 *-     handle pixel collision
 *-     handle split screen gameplay
 *******************************************************************************************************************************
 *                                                                                                                  -lain
 */















































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


    if (IMG_Init(IMG_INIT_PNG)<0) {
        printf("IMG_Init failed: %s\n", IMG_GetError());
        return 1;
    }




    // load font :
    TTF_Font *font = NULL;
    font = TTF_OpenFont(FREDOKA_PATH,28);

    // define text surf
    SDL_Color color = {255,255,255};
    SDL_Surface *text_surface = NULL;


    // render text :
    text_surface = TTF_RenderText_Solid(font,"play",color);



    Game game;
    game.height = HEIGHT;
    game.width = WIDTH;
    game.title = "LUCK UP";
    game.state = 1;
    game.quite = 0;
    game.screen = SDL_SetVideoMode(game.width,game.height,32,SDL_SWSURFACE | SDL_RESIZABLE);


    // this is how you load images
    SDL_Surface *bird = IMG_Load(BIRD_R01_PATH);

    // scale its size:
    bird = scaleSurface(bird, bird->w /3, bird->h/3 );


    // load BG
    load_background(&game);



    // an array of text
    char *button_name_list[] = {"play"};
    int b_cnt = sizeof(button_name_list)/sizeof(*button_name_list);

    Button button[b_cnt];

    // discovered i3a9a fi C
    printf("%d\n",b_cnt);





    //declaire a button
    Button pur;
    pur.text = "play";
    pur.txt_color = (SDL_Color){225,225,225}; //red ;

    pur.w = 300;
    pur.h = 200;
    pur.x = (WIDTH - pur.w)/2 ;
    pur.y = (HEIGHT - pur.h)/2 ;




    //load image
    SDL_Surface *purple = IMG_Load(BUTTON_PNG_PATH );

    //scale
    purple = scaleSurface(purple, pur.w, pur.h );






    // basic : ( trying to figure out text )



    // from tools
    //pur.basic = create_color_surface(300 , 200 ,161,134,190 );



    // this values where tested manually they only work for my image -lain (the work has to be revisited if another button was chosen)
    pur.b_rect = (SDL_Rect){(pur.x + pur.w/22) , (pur.y + pur.h/2.9), (pur.w - pur.w/15), pur.h/3};
    // based on this rect we will create



    pur.basic = create_color_surface(pur.b_rect.w , pur.b_rect.h ,0,0,0 );









    // custom :
    //assing surf
    pur.hovered = purple;
    // assign rect
    pur.rect = (SDL_Rect) { pur.x,pur.y,pur.w,pur.h };


    // text surf :
    pur.text_surface = create_centered_label(pur.b_rect,font,pur.text,pur.txt_color);

























    //render_buttton(&game,game.main_menu,1);






    // att to create buttons





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
        //SDL_BlitSurface(bird,NULL,game.screen,NULL);



        // basic
        SDL_BlitSurface(pur.basic,NULL,game.screen,&pur.b_rect);
        // rend  button att
        SDL_BlitSurface(pur.hovered,NULL,game.screen,&pur.rect);


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


/*
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 100, 100, 100));

    // Intersecting squares
    SDL_Surface *redSquare = SDL_CreateRGBSurface(SDL_SWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(redSquare, NULL, SDL_MapRGB(redSquare->format, 255, 0, 0));
    SDL_Surface *blueSquare = SDL_CreateRGBSurface(SDL_SWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(blueSquare, NULL, SDL_MapRGB(blueSquare->format, 0, 0, 255));
    SDL_Surface *yellowSquare = SDL_CreateRGBSurface(SDL_SWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(yellowSquare, NULL, SDL_MapRGB(yellowSquare->format, 255, 255, 0));
    SDL_Surface *purpleSquare = SDL_CreateRGBSurface(SDL_SWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(purpleSquare, NULL, SDL_MapRGB(purpleSquare->format, 128, 0, 128));

    SDL_Rect redPos = {120, 120, 0, 0};
    SDL_Rect bluePos = {140, 120, 0, 0};
    SDL_Rect yellowPos = {120, 140, 0, 0};
    SDL_Rect purplePos = {140, 140, 0, 0};

    SDL_BlitSurface(redSquare, NULL, screen, &redPos);
    SDL_BlitSurface(blueSquare, NULL, screen, &bluePos);
    SDL_BlitSurface(yellowSquare, NULL, screen, &yellowPos);
    SDL_BlitSurface(purpleSquare, NULL, screen, &purplePos);

    // Text directly over squares
    TTF_Font *font = TTF_OpenFont("../src/assets/font/fredoka-one.one-regular.ttf", 28);
    SDL_Surface *text = TTF_RenderText_Blended(font, "Hello", (SDL_Color){255, 255, 255});
    if (text) {
        SDL_SetAlpha(text, SDL_SRCALPHA, 255);

        SDL_Rect textPos = {110, 125, 0, 0};


        SDL_BlitSurface(text, NULL, screen, &textPos);
        printf("Text rendered: %dx%d\n", text->w, text->h);
    } else {
        printf("Text failed: %s\n", TTF_GetError());
    }

    SDL_Flip(screen);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}

*/

