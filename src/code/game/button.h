//
// Created by lain on 4/3/25.
//

#ifndef BUTTON_H
#define BUTTON_H
#include "game.h"






Button *create_button_list( char *text_list[],int size);

void render_buttton(Game *game, Button button[],int b_cnt ) ;



#endif //BUTTON_H
