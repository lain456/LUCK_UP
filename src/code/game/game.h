//
// Created by lain on 4/3/25.
//

#ifndef GAME_H
#define GAME_H
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

// game window dimensions :
#define WIDTH 800
#define HEIGHT 600




// bird dimensions in px :
#define BIRD_OG_WIDTH 829
#define BIRD_OG_HEIGHT 773


// gameplay :
#define SQUARE_SIZE 50
#define MOVE_SPEED 5
#define FPS 60





typedef struct {
    SDL_Rect rect;
    //SDL_Surface * default ;
    SDL_Surface * hovered ;
    char *text;
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


    // background
    SDL_Surface *background;

}Game;











#endif //GAME_H
