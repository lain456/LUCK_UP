//
// Created by lain on 4/3/25.
//
#include "button.h"






// this function assing names to each button -lain
Button *create_button_list( char *text_list[],int size) {
    // init array of buttons
    Button *button = (Button *)malloc(sizeof(Button)*size);

    for(int i=0;i<size;i++) {
        button[i].text = text_list[i];
        button[i].not_hovered = IMG_Load( BACK_PNG_PATH);
        button[i].hovered = IMG_Load( BUTTON_PNG2_PATH);
        button[i].isHovered = 0;
        button[i].isPressed = 0;

        // postion the buttons


    }

   // game->main_menu = button;
}




void render_buttton(Game *game, Button button[],int b_cnt ) {
    for(int i=0;i<b_cnt;i++) {
        SDL_BlitSurface(button[i].hovered,&button[i].rect,game->screen,NULL);




    }
}



