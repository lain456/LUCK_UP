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




#include "src/code/load_menus/load_menus.h"
#include "src/code/slider/slider.h"



















//gameplay
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include"gameplay/include/game.h"
//#include "gameplay/include/player.h"
#include "gameplay/include/bullet.h"
#include "gameplay/include/enemy.h"
#include "gameplay/include/utils.h"



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
 *------travel between menus                                                                                        done  !                         ****
 *------create a tree like data structure where each node can point to a menu (menu mapping ) THIS IS HARD !!            done !                     ****
 *-------handle button actions using a current button list                                                               done!                      ****
 *                                                                                                                                                  ****
 *                                                                                                                                                  ****
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *- Tue Apr 8 04:07:12 AM CET 2025                                                                |>lain added tasks...                             ****
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-****
 *-   |> tasks added :                                                                                                                              ****
 *-                                                                                                                                                 ****
 *-             * options menu  :                                                                                                                   ****
 *                      |>higher and lower volume (slider optional )                                                                                ****
 *                      |>fullscreen on and off , choose resolution (change game status )                    done !                                 ****
 *                      |>other functionalities like an info button cuz why not....                                     done ig.....                ****
 *              * hitting escape at any point will take you back one menu back ....                             !!!!!!!                             ****
 *              * emulate menu branching                                                                  almost done...                            ****
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


// slider test
int test4()
{
    //printf("pizza = %d\n",pizza());

    Game game;
    Ini_Game(&game);
    load_background(&game);
    printf("testing ... \n");


    M_node n,n0,n1,n2;
    //create menus
    Menu play = play_menu(game) ,exit = exit_menu(game) ,options = options_menu(game) ,GET_YO_SORRY_ASS_TO_WORK = WIP_menu(game);
    // link menus to nodes

    node_Init(&n1,&play,1);  node_Init(&n0,&exit,0 );  node_Init(&n2,&options,2);  node_Init(&n,&GET_YO_SORRY_ASS_TO_WORK,3);





    game.current_node = &n2;


    // trying out sliders
//Slider s = *create_slider(&game,(SDL_Rect){(WIDTH-game.x_slider_size) *3/4,(HEIGHT -game.y_slider_size)*1/3 ,game.x_slider_size,game.y_slider_size,});
//printf("s = %d",s.val);







    //SDL_Event event;   // use the game event
    while (!game.quite) {
        SDL_GetMouseState(&game.x_mouse,&game.y_mouse);
        game.released_mouse = 0;
        //game.mouse_pressed = 0;
        while (SDL_PollEvent(&game.event)) {
            if (game.event.type == SDL_QUIT) {
                game.quite = 1;
            }
            if (game.event.type == SDL_MOUSEBUTTONDOWN) {
                game.mouse_pressed = 1;
                printf("Mouse button pressed %d\n", game.event.button.button);
            }
            if (game.event.type == SDL_MOUSEBUTTONUP) {
                game.mouse_pressed = 0;
                printf("Mouse button released %d\n", game.event.button.button);
                game.released_mouse = game.event.button.button;
                game.event.button.button = 0;
            }




        }



        update_buttons(&game,game.current_node->menu->buttonlist,game.current_node->menu->b_ct);



        switch (game.current_node->id)
        {


        case 0 :
            {
                if (game.current_node->menu-> buttonlist[0].isClicked )
                {
                    game.current_node = &n1;

                }


                if (game.current_node->menu-> buttonlist[1].isClicked )
                {
                    game.quite = 1;
                }


                break;
            }
            case 1:
                {




                    if (game.current_node->menu-> buttonlist[0].isClicked )
                    {
                        update_txt(&game.current_node->menu->buttonlist[0].txt,"P L A Y",GOLD,NULL);
                        printf("we are about to play\n");
                        break;

                    }


                    // options
                    if (game.current_node->menu-> buttonlist[1].isClicked ){
                        game.current_node = &n2;
                        break; // big fix
                    }


                    // info

                    if (game.current_node->menu-> buttonlist[2].isClicked ){
                        game.current_node = &n;
                        break;
                    }




                // quite
                    if (game.current_node->menu-> buttonlist[3].isClicked ){
                        game.current_node = &n;
                        break;
                    }

                // HELP
                if (game.current_node->menu-> buttonlist[4].isClicked ){
                    game.current_node = &n;
                    break;
                }





                    break;
                }

            case 2: //option menu
            {

                if (game.current_node->menu-> buttonlist[0].isClicked )
                {
                    update_txt(&game.current_node->menu->txtlist[0] ,"yeah that button doesn't work...",BLACK,game.main_font);
                    game.current_node->menu->slider_list[0].val -= 10;

                    game.current_node->menu->buttonlist[0].b_switch = ! game.current_node->menu->buttonlist[0].b_switch;
                    //printf("switching..\n");
                    if (game.current_node->menu->buttonlist[0].b_switch)
                    {
                        update_txt(&game.current_node->menu->buttonlist[0].txt,"volume off",GOLD,NULL);
                        game.current_node->menu->slider_list[0].val = 0;
                    }else
                    {
                        update_txt(&game.current_node->menu->buttonlist[0].txt,"volume on",GOLD,NULL);
                        //update_slider(&game,&game.current_node->menu->slider_list[0],69);
                        game.current_node->menu->slider_list[0].val = 69;
                        // this code works , the button ineed move between 0 and 69 as i switch on and off volume
                    }

                }
                if (game.current_node->menu-> buttonlist[1].isClicked )
                {
                    toggle_fullscreen(&game) ;
                }
                if (game.current_node->menu-> buttonlist[2].isClicked )
                {
                    update_txt(&game.current_node->menu->txtlist[0] ," W I P ig....",BLACK,game.big_main_font);
                    game.current_node = &n1;
                }
                //handle_slider_input(&game,&game.current_node->menu->slider_list[0]);
                update_slider(&game,&game.current_node->menu->slider_list[0],game.current_node->menu->slider_list[0].val);
                if (is_clicked(&game,&game.current_node->menu->slider_list[0].b_rect) )
                {
                    printf("clicked");
                }
                if (is_hovered(&game,&game.current_node->menu->slider_list[0].b_rect) )
                {
                    printf("hovered");
                }
                if (is_pressed(&game,&game.current_node->menu->slider_list[0].b_rect))
                {
                    printf("pressed");
                }

                break;
            }

            case 3:
            {
                if (game.current_node->menu-> buttonlist[0].isClicked )
                {
                    game.current_node = &n1;
                }
                break;
            }





            default:
                printf("get out ");
            break;





        }



















        render_background(&game);


        render_menu(&game,game.current_node->menu);
        //render_slider(&game,&s);


        SDL_Flip(game.screen);
        printf("gp %d , gr %d\n",game.mouse_pressed,game.released_mouse);
        game.event.button.button = 0;
    }




    SDL_Quit();
    return 0;

}



//random import
int displayMenu(SDL_Surface *screen, TTF_Font *font) {
    SDL_Surface *menuSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, 800, 600, 32, 0, 0, 0, 0);
    SDL_FillRect(menuSurface, NULL, SDL_MapRGB(menuSurface->format, 0, 0, 0));

    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Play Again?", textColor);
    SDL_Rect dstRect = { 300, 250, textSurface->w, textSurface->h };
    SDL_BlitSurface(textSurface, NULL, menuSurface, &dstRect);
    SDL_FreeSurface(textSurface);

    SDL_Rect yesRect = { 300, 350, 100, 50 };
    SDL_Rect noRect = { 400, 350, 100, 50 };

    SDL_FillRect(menuSurface, &yesRect, SDL_MapRGB(menuSurface->format, 0, 255, 0));
    SDL_FillRect(menuSurface, &noRect, SDL_MapRGB(menuSurface->format, 255, 0, 0));

    textSurface = TTF_RenderText_Solid(font, "Yes", textColor);
    dstRect = (SDL_Rect){ 325, 360, textSurface->w, textSurface->h };
    SDL_BlitSurface(textSurface, NULL, menuSurface, &dstRect);
    SDL_FreeSurface(textSurface);

    textSurface = TTF_RenderText_Solid(font, "No", textColor);
    dstRect = (SDL_Rect){ 425, 360, textSurface->w, textSurface->h };
    SDL_BlitSurface(textSurface, NULL, menuSurface, &dstRect);
    SDL_FreeSurface(textSurface);

    SDL_BlitSurface(menuSurface, NULL, screen, NULL);
    SDL_Flip(screen);
    SDL_FreeSurface(menuSurface);


    SDL_Event e;
    while (1) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return 0;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                if (mouseX >= yesRect.x && mouseX <= yesRect.x + yesRect.w &&
                    mouseY >= yesRect.y && mouseY <= yesRect.y + yesRect.h) {
                    return 1; // Yes
                } else if (mouseX >= noRect.x && mouseX <= noRect.x + noRect.w &&
                           mouseY >= noRect.y && mouseY <= noRect.y + noRect.h) {
                    return 0; // No
                }
            }
        }
    }
}

// gameplay test
int test5()
{











    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    TTF_Font *font = TTF_OpenFont(FREDOKA_PATH, 24);
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Surface *screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        printf("SDL_SetVideoMode Error: %s\n", SDL_GetError());
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    Player player;
    initPlayer(&player);

    Bullet bullets[MAX_BULLETS] = {0};
    int bulletCount = 0;

    Enemy enemies[MAX_ENEMIES] = {0};
    int enemyCount = 0;
    spawnEnemies(enemies, &enemyCount);
    SDL_Event e;
    int quit = 0;
    int mouseX, mouseY;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mouseX, &mouseY);
                shootBullet(bullets, &bulletCount, mouseX, mouseY, player.x + SQUARE_SIZE / 2, player.y + SQUARE_SIZE / 2);
            } else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
                handlePlayerMovement(&player, e);
                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_f && (SDL_GetModState() & KMOD_CTRL)) {
                    toggleFullscreen(screen);
                } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                    int playAgain = displayMenu(screen, font);
                    if (playAgain == 0) {
                        quit = 1;
                    } else {
                        // Reset game state
                        initPlayer(&player);
                        bulletCount = 0;
                        enemyCount = 0;
                        for (int i = 0; i < MAX_ENEMIES; i++) {
                            enemies[i].active = false;
                        }
                        //spawnEnemies(enemies, &enemyCount);
                    }
                }
            }
        }

        updatePlayer(&player);
        updateBullets(bullets, &bulletCount, enemies, enemyCount);
        updateEnemies(enemies, enemyCount, player.x, player.y);
        checkCollisions(enemies, enemyCount, player.x, player.y, &player.health);

        // Level up when enemies die
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemies[i].active) {
                player.level++;
                enemies[i].active = true;
                enemies[i].x = rand() % 800;
                enemies[i].y = rand() % 600;
            }
        }

        if (player.health <= 0) {
            int playAgain = displayMenu(screen, font);
            if (playAgain == 0) {
                quit = 1;
            } else {
                // Reset game state
                initPlayer(&player);
                bulletCount = 0;
                enemyCount = 0;
                for (int i = 0; i < MAX_ENEMIES; i++) {
                    enemies[i].active = false;
                }
                spawnEnemies(enemies, &enemyCount);
            }
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        renderPlayer(screen, &player);
        renderBullets(screen, bullets, bulletCount);
        renderEnemies(screen, enemies, enemyCount);
        renderStatus(screen, player.health, bulletCount, player.level, font);

        SDL_Flip(screen);

        SDL_Delay(16);
    }
    TTF_CloseFont(font);
    TTF_Quit();
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



/*  nodes be like :
 *
 *
 *
 *
 *                              |->
 *                              |->n2
 ********************* n0 -> n1 |->n
 *                              |->n0
 *
 *
 *
 *
 *
 *
 */



int main(int argc, char *argv[]){
    // obv testing ....
    //return test();
    //return test3();

    //return test5();


    printf("pizza = %d\n",pizza());
    Game game;
    Ini_Game(&game);
    load_background(&game);
    printf("testing ... \n");


    M_node n;
    M_node n1;
    M_node n0;
    M_node n2;


    Menu play = play_menu(game); ;
    Menu exit = exit_menu(game);
    Menu options = options_menu(game);
    Menu GET_YO_SORRY_ASS_TO_WORK = WIP_menu(game);
    node_Init(&n0,&exit,0 );
    node_Init(&n1,&play,1);
    node_Init(&n2,&options,2);
    //WIP
    node_Init(&n,&GET_YO_SORRY_ASS_TO_WORK,-1);

    printf("%p\n",n0.parent);

    //n1.parent = &n0;

    game.current_node = &n1;



    //node_Init(&exit,play_menu(game));

    // WIP exit



    //cooked = exit_menu(game);


   // main_menu.parent = &exit;




    game.current_menu = n1.menu;

    //SDL_Event event;   // use the game event
    while (!game.quite) {
        SDL_GetMouseState(&game.x_mouse,&game.y_mouse);
        game.released_mouse = 0;
        while (SDL_PollEvent(&game.event)) {
            if (game.event.type == SDL_QUIT) {
                game.quite = 1;
            }
            if (game.event.type == SDL_MOUSEBUTTONDOWN) {
                game.mouse_pressed = 1;
                //printf("Mouse button pressed %d\n", game.event.button.button);
            }
            if (game.event.type == SDL_MOUSEBUTTONUP) {
                game.mouse_pressed = 0;
                //printf("Mouse button released %d\n", game.event.button.button);
                game.released_mouse = game.event.button.button;
                game.event.button.button = 0;
            }
        }



        update_buttons(&game,game.current_node->menu->buttonlist,game.current_node->menu->b_ct);



        switch (game.current_node->id)
        {

        case -1:
            {
                if (game.current_node->menu-> buttonlist[0].isClicked )
                {
                    game.current_node = &n1;
                }
                break;
            }


        case 0 :
            {
                if (game.current_node->menu-> buttonlist[0].isClicked )
                {
                    game.current_node = &n1;

                }


                if (game.current_node->menu-> buttonlist[1].isClicked )
                {
                    game.quite = 1;
                }


                break;
            }
            case 1:
                {




                    if (game.current_node->menu-> buttonlist[0].isClicked )
                    {
                        update_txt(&game.current_node->menu->buttonlist[0].txt,"P L A Y",GOLD,NULL);
                        printf("we are about to play\n");
                        return  test5();
                        break;

                    }


                    // options
                    if (game.current_node->menu-> buttonlist[1].isClicked ){
                        game.current_node = &n2;
                        break; // big fix
                    }


                    // info

                    if (game.current_node->menu-> buttonlist[2].isClicked ){
                        game.current_node = &n;
                        break;
                    }




                // quite
                    if (game.current_node->menu-> buttonlist[3].isClicked ){
                        game.current_node = &n0;
                        break;
                    }

                // HELP
                if (game.current_node->menu-> buttonlist[4].isClicked ){
                    game.current_node = &n;
                    break;
                }





                    break;
                }

            case 2:
            {

               if (game.current_node->menu-> buttonlist[0].isClicked )
                {
                    update_txt(&game.current_node->menu->txtlist[0] ,"yeah that button doesn't work...",BLACK,game.main_font);
                    game.current_node->menu->slider_list[0].val -= 10;

                    game.current_node->menu->buttonlist[0].b_switch = ! game.current_node->menu->buttonlist[0].b_switch;
                    //printf("switching..\n");
                    if (game.current_node->menu->buttonlist[0].b_switch)
                    {
                        update_txt(&game.current_node->menu->buttonlist[0].txt,"volume off",GOLD,NULL);
                        game.current_node->menu->slider_list[0].val = 0;
                    }else
                    {
                        update_txt(&game.current_node->menu->buttonlist[0].txt,"volume on",GOLD,NULL);
                        //update_slider(&game,&game.current_node->menu->slider_list[0],69);
                        game.current_node->menu->slider_list[0].val = 69;
                        // this code works , the button ineed move between 0 and 69 as i switch on and off volume
                    }

                }
                if (game.current_node->menu-> buttonlist[1].isClicked )
                {
                    toggle_fullscreen(&game) ;
                }
                if (game.current_node->menu-> buttonlist[2].isClicked )
                {
                    update_txt(&game.current_node->menu->txtlist[0] ," W I P ig....",BLACK,game.big_main_font);
                    game.current_node = &n1;
                    break;
                }
                //handle_slider_input(&game,&game.current_node->menu->slider_list[0]);
                update_slider(&game,&game.current_node->menu->slider_list[0],game.current_node->menu->slider_list[0].val);
                //the vol is being updated
                game.music_volume = game.current_node->menu->slider_list[0].val;
                /*
                if (is_clicked(&game,&game.current_node->menu->slider_list[0].b_rect) )
                {
                    printf("clicked");
                }
                if (is_hovered(&game,&game.current_node->menu->slider_list[0].b_rect) )
                {
                    printf("hovered");
                }
                if (is_pressed(&game,&game.current_node->menu->slider_list[0].b_rect))
                {
                    printf("pressed");
                }
                */

                break;
            }







            default:
                printf("get out ");
            break;





        }



















        render_background(&game);


        render_menu(&game,game.current_node->menu);



        SDL_Flip(game.screen);
    }




    SDL_Quit();
    return 0;

}















































































































































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

}


    */















