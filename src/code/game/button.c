//
// Created by lain on 4/3/25.
//
#include "button.h"
#include "../tools/tools.h"





// this function assing names to each button -lain
Button *create_buttons( char *text_list[],int size) {
    // init array of buttons
    Button *button = (Button *)malloc(sizeof(Button)*size);

    for(int i=0;i<size;i++) {
        button[i].txt.writen = text_list[i];
        button[i].not_hovered = IMG_Load( BACK_PNG_PATH);
        button[i].hovered = IMG_Load( BUTTON_PNG2_PATH);
        button[i].isHovered = 0;
        button[i].isPressed = 0;

        // postion the buttons


    }

   // game->main_menu = button;
}




void render_buttons(Game *game, Button button[],int b_cnt ) {
    for(int i=0;i<b_cnt;i++) {
        SDL_BlitSurface(button[i].hovered,&button[i].rect,game->screen,NULL);




    }
}




// first let's render a button
void render_button(Game *game,Button b) {

    if(b.isHovered) {
        SDL_BlitSurface(b.hovered,NULL,game->screen,&b.rect);
        SDL_BlitSurface(b.txt.surf, NULL, game->screen, &b.txt.rect);

        // render text



    }else {

        SDL_BlitSurface(b.not_hovered,NULL,game->screen,&b.rect);
        SDL_BlitSurface(b.txt.surf, NULL, game->screen, &b.txt.rect);
    }



}


Button *create_button(Game *game ,int x,int y,int h,int w ,char* text ,SDL_Color color ,int type ) {
    Button *button = (Button *)malloc(sizeof(Button));
    button->txt.writen = text;
    button->x = x;
    button->y = y;
    button->w = w;
    button->h = h;
    button->rect = (SDL_Rect) { x,y,w,h };
    button->type = type;
    button->isHovered = 0;
    button->isPressed = 0;
    button->txt.color = color;
    button->x_center = x + (w/2);
    button->y_center = y + (h/2);
    button->not_hovered = scaleSurface(game->b_purple, w, h );
    button->hovered = scaleSurface(game->b_yellow, w, h );




    // create txt surf
    button->txt.surf = TTF_RenderText_Blended(game->main_font,button->txt.writen,button->txt.color);
    //txt surf
    button->txt.rect = (SDL_Rect){0, 0, button->txt.surf->w, button->txt.surf->h};


    // figure out b_rect
    switch (type) {
        case 1: {
            button->b_rect.x = x + (w/22);
            button->b_rect.y = y + (h/2.9);
            button->b_rect.w = button->w  -(w/15);
            button->b_rect.h = button->h - (h*2/3);

        }break;

        default:
            printf("no button type exist ");
    }


    // basic surf..
    button->basic = create_color_surface(button->b_rect.w , button->b_rect.h ,0,0,0 );

    //text rect
    button->txt.rect = (SDL_Rect){
        button->b_rect.x + ( button->b_rect.w - button->txt.surf->w)/2,
        button->b_rect.y + ( button->b_rect.h - button->txt.surf->h)/2,
           button->txt.surf->w,
           button->txt.surf->h,

    };
























    return button;
}




