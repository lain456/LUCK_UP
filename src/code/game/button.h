//
// Created by lain on 4/3/25.
//

#ifndef BUTTON_H
#define BUTTON_H
#include "game.h"






Button *create_buttons( char *text_list[],int size);

void render_buttons(Game *game, Button button[],int b_cnt ) ;



//Button create_button( char *text_list[],i;


void render_button(Game *game,Button b);



Button *create_button(Game *game ,int x,int y,int h,int w ,char* text ,SDL_Color color ,int type );



#endif //BUTTON_H
