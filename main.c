#include "src/code/game/game.h"
#include "src/code/tools/tools.h"
#include "src/code/Player/player.h"
#include"src/code/Background/background.h"
#include "src/code/button/button.h"
#include <stdlib.h>
#include <stdio.h>
#include <bits/types/sigevent_t.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "src/code/text/txt.h"
#include "src/code/menu/menu.h"



/*
 *to do list  :
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 *******************************************************************************************************************************************************
 *------manual text render    |                                                                                       done!                         ****
 *                            |-> apply                                                                               done!                         ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *------scale button handling   |                                                                                                                   ****
 *                              |-> render buttons                                                                     done!                        ****
 *                              |-> create buttons :                                                                                                ****
 *                                  |> manual                                                                          done!                        ****
 *                                  |> automation                                                                      done!                        ****
 *******************************************Sun Apr 6 02:11:29 AM CET 2025******************************************************************************
 *                                                                                                                                                  ****
 *------check if the button is hovered                                                                                 done!                        ****
 *------check if the single button is being pressed                                                                    done!                        ****
 *------check if button is being clicked                                                                                done!                       ****
 *                                                                                                                                                  ****
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *- Tue Apr 8 12:14:11 AM CET 2025 : button handeling is done                                                           |>lain                      ****
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *------create a menu                                                                                                   done!                       ****
 *------render menu                                                                                                     done!                       ****
 *------menu handling                                                                                               done ig ?                       ****
 *------travel between menus                                                                                        WIP...                          ****
 *------create a tree like data structure where each node can point to a menu (menu mapping ) THIS IS HARD !!                                       ****
 *-------handle button actions using a current button list                                                           done ig ?                      ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *- Tue Apr 8 04:07:12 AM CET 2025                                                                |>lain added tasks...                             ****
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *-   |> tasks added :                                                                                                                              ****
 *-                                                                                                                                                 ****
 *-             * options menu  :                                                                                                                   ****
 *                      |>higher and lower volume (slider optional )                                                                                ****
 *                      |>fullscreen on and off , choose resolution (change game status )                                                           ****
 *                      |>other functionalities like an info button cuz why not....                                                                 ****
 *              * hitting escape at any point will take you back one menu back ....                                                                 ****
 *              * emulate menu branching                                                                                                            ****
 *              * init menu - it takes &game and create everything from the start                                                                   ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *    |>move to the gameplay                                                                                                                        ****
 *    |>player mvt                                                                                                                                  ****
 *    |>handle animation                                                                                                                            ****
 *    |>handle player hit-box and collisions                                                                                                        ****
 *    |>handle pixel collision                                                                                                                      ****
 *    |>handle split screen gameplay #ALSO HARD !!!!                                                                                                ****
 *                                                                                                                                                  ****
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *-----------------------------------------------------------------------||-------------------------------------------------------------------------****
 *      |>|>|>update log :                                               ||notes :                                                                  ****
 *-----------------------------------------------------------------------||-------------------------------------------------------------------------****
 *              Mon Apr 7 12:36:22 PM CET 2025                           ||                                                                         ****
 *-----------------------------------------------------------------------||-------------------------------------------------------------------------****
 *              Tue Apr 8 04:23:22 AM CET 2025                           ||                                                                         ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 *                                                                                                          -lain                                   ****
 *******************************************************************************************************************************************************
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *******************************************************************************************************************************************************
 */











/*
 *
 *                                              **********************************************************
 *                                              * * *       T E S T I N G        F I E L D           * * *
 *                                              **********************************************************
 *
 */
/*
int test( ) {
    Game game;
    Ini_Game(&game);
    printf("testing ... \n");
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    int width = 1080 ,height = 720;
    int quit =0;
    int x,y;

    SDL_Surface *screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 10, 10, 10));





   Button yel = *create_button(&game, (WIDTH - 200 )/2,  50 ,200 ,200,"exit",(SDL_Color){0,0,0},1);



    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        int z = 10;
        //yel.txt.writen = f"z =  f{x}";
        char res[100] ;
        sprintf(res,"%d",z);
        printf("%s\n",res);
        strcat(yel.txt.writen,res);
        render_button(&game,yel.txt.writen,1);
        SDL_Flip(screen);
    }




    SDL_Quit();
    return 0;
}
*/
int test2(){

        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL_Init failed: %s\n", SDL_GetError());
            return 1;
        }

        // Initialize SDL_ttf
        if (TTF_Init() < 0) {
            printf("TTF_Init failed: %s\n", TTF_GetError());
            SDL_Quit();
            return 1;
        }

        // Create a window
        SDL_Surface *screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
        if (!screen) {
            printf("SDL_SetVideoMode failed: %s\n", SDL_GetError());
            TTF_Quit();
            SDL_Quit();
            return 1;
        }

        // Load a font (replace "arial.ttf" with the path to your font file)
        TTF_Font *font = TTF_OpenFont(FREDOKA_PATH, 24); // 24 is the font size
        if (!font) {
            printf("TTF_OpenFont failed: %s\n", TTF_GetError());
            TTF_Quit();
            SDL_Quit();
            return 1;
        }

        // Variable to render
        int z = 42; // Example value

        // Buffer to hold the text
        char text[50];
        sprintf(text, "Value of z: %d", z); // Combine text and z

        // Define text color (white)
        SDL_Color textColor = {255, 255, 255};

        // Render the text to a surface
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
        if (!textSurface) {
            printf("TTF_RenderText_Solid failed: %s\n", TTF_GetError());
            TTF_CloseFont(font);
            TTF_Quit();
            SDL_Quit();
            return 1;
        }

        // Position to blit the text (e.g., at (100, 100))
        SDL_Rect dest = {100, 100, 0, 0};

        // Blit the text surface to the screen
        SDL_BlitSurface(textSurface, NULL, screen, &dest);

        // Update the screen
        SDL_Flip(screen);

        // Wait for a few seconds (or handle events in a loop)
        SDL_Delay(30000); // Show for 3 seconds

        // Cleanup
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();

        return 0;

}


// menu test
int test3()
{
    Game game;
    Ini_Game(&game);
    load_background(&game);
    printf("testing ... \n");


    M_node root_menu;

    Menu play  ;
    Menu cooked;

    Init_Menu(&play);
    Init_Menu(&cooked);



    //custom play_menu
    play.b_ct =6;
    play.txt_ct = 3 ;
    play.t_margine =10;
    play.b_margine = 20;


    // mem aloc
    play.buttonlist = (Button*)malloc(sizeof(Button)*play.b_ct);
    play.txtlist = (Text*)malloc(sizeof(Text)*play.txt_ct);




    //Button names and txts
    char *button_strings[] = {"play","options"," ","help","quit","lain"};
    for (int i = 0; i < play.b_ct; i++)
    {
        play.buttonlist[i] = *create_button(&game,(WIDTH - game.x_button_size)/2,300 ,game.y_button_size,game.x_button_size,button_strings[i],WHITE,1);
    }



    y_order_buttons(play.buttonlist ,play.b_margine,play.b_ct);

    //b_pos_update(&play.buttonlist[4],100 ,100);




    play.txtlist[0] = *create_txt(" M A I N    G A M E ",game.big_main_font,BLACK,20,20);
    play.txtlist[1] = *create_txt("prsented by lain",game.main_font,BLACK,play.txtlist[0].rect.x,play.txtlist[0].rect.y + play.txtlist[0].rect.h + play.t_margine);
    play.txtlist[2] = *create_txt("game logo here",game.main_font,BLACK,game.width - 250 , game.height - 40 - play.t_margine);










    game.current_menu = &play;



















    //SDL_Event event;   // use the game event
    while (!game.quite) {
        SDL_GetMouseState(&game.x_mouse,&game.y_mouse);
        game.released_mouse = 0;
        while (SDL_PollEvent(&game.event)) {
            if (game.event.type == SDL_QUIT) {
                game.quite = 1;
            }
            if (game.event.type == SDL_MOUSEBUTTONUP)
            {

                printf("Mouse button released\n");
                game.released_mouse = game.event.button.button;
                game.event.button.button = 0;


            }

        }


        update_buttons(&game,game.current_menu->buttonlist,game.current_menu->b_ct);







        if (game.current_menu-> buttonlist[0].isClicked)
        {
            update_txt(&game.current_menu->buttonlist[0].txt,"P L A Y",GOLD,NULL);

        }











        render_background(&game);
        SDL_BlitSurface(play.buttonlist[4].basic,NULL,game.screen,&play.buttonlist[4].b_rect);
        //SDL_BlitSurface(play.buttonlist[3].basic,NULL,game.screen,&play.buttonlist[3].b_rect);

        render_menu(&game,game.current_menu);



        SDL_Flip(game.screen);
    }




    SDL_Quit();
    return 0;

}


/*
 *
 *                                              **********************************************************
 *                                              * * *       E N D         O F        F I E L D       * * *
 *                                              **********************************************************
 *
 */







int main(int argc, char *argv[]){
    // obv testing ....
    //return test();
    return test3();


    /*




    // init game
    Game game;

    Ini_Game(&game);
    load_background(&game);




    // an array of text


    // discovered i3a9a fi C





    //declaire a button


    //pur.hovered = game.b_purple;
    //pur.not_hovered = game.b_yellow;



    // declaire button list
    Button *buttonlist = (Button *)malloc(sizeof(Button) * 4);
    if (buttonlist == NULL) {
        printf("Failed to allocate buttonlist\n");
        return;
    }

    game.x_button_size = 200;
    game.y_button_size = 150;
    int margin = 10;

    char *button_name_list[] = {"LAIN","options" , "quiz","exit"};

    buttonlist[0] = *create_button(&game, (WIDTH - game.x_button_size) / 2, (HEIGHT) * 2/5, game.y_button_size, game.x_button_size, button_name_list[0], BLACK, 1);
    buttonlist[1] = *create_button(&game , buttonlist[0].x , buttonlist[0].y + buttonlist[0].b_rect.h + margin , game.y_button_size, game.x_button_size,button_name_list[1], BLACK, 1) ;
    buttonlist[2] = *create_button(&game , buttonlist[1].x , buttonlist[1].y + buttonlist[1].b_rect.h + margin, game.y_button_size, game.x_button_size,button_name_list[2], BLACK, 1) ;
    buttonlist[3] = *create_button(&game , buttonlist[2].x , buttonlist[2].y + buttonlist[2].b_rect.h + margin , game.y_button_size, game.x_button_size,button_name_list[3], BLACK, 1) ;




    // creating a title
    Text title;
    title = *create_txt("T H I S   I S    T H E     G A M E     T I T L E",game.big_main_font,WHITE,20,20 );
    x_center_txt(&game,&title);






    // creating a menu
    Menu *game_menu = (Menu*)malloc(sizeof(Menu));

    game_menu->b_ct = 4;
    game_menu->txt_ct = 2;
    game_menu->t_margine=50;



    game_menu->txtlist = (Text *)malloc(sizeof(Text) * game_menu->txt_ct);
    game_menu->buttonlist = (Text *)malloc(sizeof(Button) * game_menu->b_ct);

    // the title has 2 lines so i'll do that manually
    game_menu->txtlist[0] = *create_txt("THIS IS",game.big_main_font,BLACK,20,20);
    x_center_txt(&game,&game_menu->txtlist[0]);

    game_menu->txtlist[1] = *create_txt("OUR LIL GAME...",game.big_main_font,BLACK,20, game_menu->txtlist[0].rect.y+game_menu->t_margine);
    x_center_txt(&game,&game_menu->txtlist[1]);







    // the real deal...
    M_node root_menu;
    root_menu.parent =NULL;
    root_menu.menu = (Menu *)malloc(sizeof(Menu));

    root_menu.menu->b_ct = 5;
    root_menu.menu->txt_ct = 3;
    root_menu.menu->t_margine=10;

    // mem allocation ...
    root_menu.menu->txtlist = (Text *)malloc(sizeof(Text) * root_menu.menu->txt_ct);
    root_menu.menu->buttonlist = (Button *)malloc(sizeof(Button) * root_menu.menu->b_ct);

    // create txt
    root_menu.menu->txtlist[0] = *create_txt(" M A I N    G A M E ",game.big_main_font,BLACK,20,20);
    x_center_txt(&game,&root_menu.menu->txtlist[0]);
    root_menu.menu->txtlist[1] = *create_txt("prsented by lain",game.main_font,BLACK,root_menu.menu->txtlist[0].rect.x,root_menu.menu->txtlist[0].rect.y + root_menu.menu->txtlist[0].rect.h + root_menu.menu->t_margine);
    x_center_txt(&game,&root_menu.menu->txtlist[1]);
    root_menu.menu->txtlist[2] = *create_txt("game logo here",game.main_font,BLACK,game.width - 250 , game.height - 40 - root_menu.menu->t_margine);

    // create buttons
    root_menu.menu->buttonlist[0] =buttonlist[0];
    root_menu.menu->buttonlist[1] =buttonlist[1];
    root_menu.menu->buttonlist[2] =buttonlist[2];
    root_menu.menu->buttonlist[3] =buttonlist[3];
    root_menu.menu->buttonlist[4] = *create_button(&game , 20 , HEIGHT - 300 , root_menu.menu->buttonlist[4].h,root_menu.menu->buttonlist[4].w,"L A i N",GOLD,1 );


    // update menu
    game.current_menu = root_menu.menu;















    while(!game.quite ) {
        //event.button.button = 0;
        SDL_GetMouseState(&game.x_mouse,&game.y_mouse);
        game.released_mouse = 0;



        while (SDL_PollEvent(&game.event)) {
            if (game.event.type == SDL_QUIT) {
                game.quite = 1;
            }


            if (game.event.type == SDL_MOUSEBUTTONUP)
            {

                printf("Mouse button released\n");
                game.released_mouse = game.event.button.button;
                game.event.button.button = 0;


            }


        }


        // tryine to hover click test
        update_buttons(&game,&game.current_menu->buttonlist, game.current_menu->b_ct);


        // action test
        if (game.current_menu-> buttonlist[0].isClicked)
        {
            update_txt(&game.current_menu->buttonlist[0].txt,"P L A Y",GOLD,NULL);

        }
        if (game.current_menu->buttonlist[3].isClicked)
        {
            update_txt(&game.current_menu->buttonlist[3].txt,"K Y S",WHITE,NULL);

        }








        render_background(&game);
        render_menu(&game,game.current_menu);
























        SDL_Flip(game.screen);
        //printf("%d\n", game.released_mouse);
    }



    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();


    printf("%s",buttonlist[0].txt.writen);
    return 0;




    */
}














