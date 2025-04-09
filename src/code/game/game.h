//
// Created by lain on 4/3/25.
//

#ifndef GAME_H
#define GAME_H
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<math.h>



// game window dimensions :
#define WIDTH 1080
#define HEIGHT 720


// SDL colors
#define BLACK (SDL_Color){0,0,0}
#define WHITE (SDL_Color){255,255,255}
#define GOLD (SDL_Color){255,215,0}



// bird dimensions in px :
#define BIRD_OG_WIDTH 829
#define BIRD_OG_HEIGHT 773







//paths used :
//basic config
#define BACK_PNG_PATH "../src/assets/grphics/basic/back.png"
#define BUTTON_PNG_PATH "../src/assets/grphics/basic/button.png"
#define BUTTON_PNG2_PATH "../src/assets/grphics/basic/button_2.png"
//************************************************************************************//
//bird config
#define BIRD_R01_PATH "../src/assets/grphics/characters/bird/flying to the right/b0.png"
#define BIRD_R02_PATH "../src/assets/grphics/characters/bird/flying to the right/b1.png"
#define BIRD_R03_PATH "../src/assets/grphics/characters/bird/flying to the right/b3.png"
#define BIRD_R04_PATH "../src/assets/grphics/characters/bird/flying to the right/b4.png"
//************************************************************************************//
#define BIRD_L01_PATH "../src/assets/grphics/characters/bird/flying to the right/b0.png"
#define BIRD_L02_PATH "../src/assets/grphics/characters/bird/flying to the right/b1.png"
#define BIRD_L03_PATH "../src/assets/grphics/characters/bird/flying to the right/b3.png"
#define BIRD_L04_PATH "../src/assets/grphics/characters/bird/flying to the right/b4.png"
//************************************************************************************//
//font config :
#define FREDOKA_PATH "../src/assets/font/fredoka-one.one-regular.ttf"
//************************************************************************************//




// gameplay :
#define SQUARE_SIZE 50
#define MOVE_SPEED 5
#define FPS 60

typedef struct {
    // function input
    char *writen;
    SDL_Color color;
    TTF_Font *font;
    // function output - AKA requre treatment

    SDL_Surface *surf;
    SDL_Rect rect;
}Text;


typedef struct {

    int h,w,x,y,x_center,y_center,type;
    //prototype
    SDL_Rect b_rect;
    SDL_Surface *basic;
    SDL_Surface *final;
    // custom
    SDL_Rect rect;
    SDL_Surface * not_hovered; ;
    SDL_Surface * hovered ;
    //text
    Text txt;

    //state
    int isHovered;
    int isPressed;
    int isClicked;
}Button;





typedef struct
{
    // menu elements :
    Button *buttonlist;
    int b_ct;
    Text *txtlist;

    int txt_ct;
    SDL_Surface *background;
    int t_margine,b_margine;
}Menu;



// creating nodes for our tree




typedef struct M_node
{
    struct M_node *parent;
    Menu *menu;
    // child_list size is included in the Menu->b_ct  AKA number of buttons
    struct M_node *child_list;
}M_node;










typedef struct {
    //momvements
    int x, y;
    float x_speed, y_speed;
    float x_accel, y_accel;
    //stats
    int health;
    int level; // Add level attribute
    // direction
    int move;

    // animation spritsheet WIP
    SDL_Surface *surface;
    SDL_Surface * flying_to_the_right[4];
    SDL_Surface * flying_to_the_left[4];


    // fight animation WIP

    int player_num;

} Player;

typedef struct {
    SDL_Event event;




    char *title;
    int width;
    int height;



    SDL_Surface *screen;




    int fullscreen;
    int state;
    int quite;
    Player *player;
    TTF_Font *main_font;
    TTF_Font * mid_font;
    TTF_Font *big_main_font;





    // mouse and button stuff
    int x_mouse,y_mouse,x_button_size,y_button_size,margin;
    int released_mouse;






    //often used suf will be here :
    // background
    SDL_Surface *background;
    SDL_Surface *b_yellow;
    SDL_Surface *b_purple;



    // the real deal ...
    Menu *current_menu;


}Game;


void Ini_Game(Game *game);








#endif //GAME_H
