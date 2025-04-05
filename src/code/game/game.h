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





// bird dimensions in px :
#define BIRD_OG_WIDTH 829
#define BIRD_OG_HEIGHT 773



//paths used :
//basic config
#define BACK_PNG_PATH "../src/assets/grphics/basic/back.png"
#define BUTTON_PNG_PATH "../src/assets/grphics/basic/button.png"
#define BUTTON_PNG2_PATH "../src/assets/grphics/basic/button_selected.png"
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
    int h,w,x,y,x_center,y_center;
    //prototype
    SDL_Rect b_rect;
    SDL_Surface *basic;
    SDL_Surface *final;
    // custom
    SDL_Rect rect;
    SDL_Surface * not_hovered; ;
    SDL_Surface * hovered ;
    //text
    char *text;
    SDL_Color txt_color;
    SDL_Surface *text_surface;
    //state
    int isHovered;
    int isPressed;
}Button;










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
    char *title;
    int width;
    int height;
    SDL_Surface *screen;
    int fullscreen;
    int state;
    int quite;
    Player *player;


    // this is a matrix , rows are menus and cols are the buttons for each menu
    Button **layout ;

    // for the first menu :
    Button *main_menu;
    int bt_count;


    // background
    SDL_Surface *background;
}Game;











#endif //GAME_H
