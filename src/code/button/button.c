//
// Created by lain on 4/3/25.
//
#include "button.h"
#include "../tools/tools.h"
#include "../text/txt.h"





// this function assing names to each button -lain

// W I P
/*
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

*/





int is_hovered(Game *game, SDL_Rect *rect)
{

    if (rect->x + rect->w>game->x_mouse && game->x_mouse>rect->x && rect->y + rect->h > game->y_mouse && game->y_mouse > rect->y)
    {
        return  1;
    }else
    {
        return  0;
    }

}



int is_pressed(Game *game, SDL_Rect *rect){

  return is_hovered(game,rect)&& game->event.button.button !=0;
  }


int is_clicked(Game *game, SDL_Rect *rect){
  return is_hovered(game,rect)&& game->released_mouse!=0;
  }



int button_is_clicked(Game *game, Button *button){
  return is_clicked(game,&button->b_rect);
}


void update_buttons(Game *game, Button *buttons,int size)
{

    for(int i=0;i<size;i++)
    {

            // check if they are hovered
            if (is_hovered(game,&buttons[i].b_rect))
            {
                buttons[i].isHovered = 1;
            }else
            {
                buttons[i].isHovered = 0;
            }

            // if it's beiing pressed ... can be needed for animations
            if (is_pressed(game,&buttons[i].b_rect)){
              buttons[i].isPressed = 1;
              }else{
                buttons[i].isPressed = 0;
            }


            // if it's clicked , used for activating functions ,
            if (is_clicked(game,&buttons[i].b_rect)){
              buttons[i].isClicked = 1;
              }else{
                buttons[i].isClicked = 0;
            }

    }


}



// first let's render a button
void render_button(Game *game,Button *b,int hover)
{
    // create txt surf

    // hover should be 1 if it's wanted





    // turn this on if you wanna see the button hitbox
    //SDL_BlitSurface(b->basic,NULL,game->screen,&b->b_rect);

    if(b->isHovered) {
        SDL_BlitSurface(b->hovered,NULL,game->screen,&b->rect);
        SDL_BlitSurface(b->txt.surf, NULL, game->screen, &b->txt.rect);   // render text





    }else {

        SDL_BlitSurface(b->not_hovered,NULL,game->screen,&b->rect);
        SDL_BlitSurface(b->txt.surf, NULL, game->screen, &b->txt.rect);
    }
}


Button *create_button(Game *game ,int x,int y,int h,int w ,char* text ,SDL_Color color ,int type ) {

    Button *button = (Button *)malloc(sizeof(Button));
    button->txt.writen = text;
    button->txt.font = game->main_font;
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









    // figure out b_rect
    switch (type) {
        case 1: {
            button->b_rect.x = x + (w/22);
            button->b_rect.y = y + (h/2.9);
            button->b_rect.w = button->w  -(w/15) ;
            button->b_rect.h = button->h - (h*2/3);

        }break;

        default:
            printf("no button type exist ");
    }


    // basic surf..
    button->basic = create_color_surface(button->b_rect.w , button->b_rect.h ,255,0,0 );





    //update_txt(&button->txt,text,color,game->main_font);



   button->txt.surf = TTF_RenderText_Blended(game->main_font,button->txt.writen,button->txt.color);
   //printf("%s \n",button->txt.writen);


   // button->txt.rect = (SDL_Rect){0, 0, button->txt.surf->w, button->txt.surf->h};


    button->txt.rect = (SDL_Rect){
        button->b_rect.x + ( button->b_rect.w - button->txt.surf->w)/2,
        button->b_rect.y + ( button->b_rect.h - button->txt.surf->h)/2,
           button->txt.surf->w,
           button->txt.surf->h,

    };


























    return button;



}









void render_buttons(Game *game, Button button[],int b_cnt ){
  // just render them dude
  for (int i=0;i<b_cnt;i++){
    render_button(game,&button[i],1);
   }
 }

void b_pos_update(Button *button,int new_x,int new_y)
{
    int g_b_x, g_b_y; // rect / b_rect relation
    int t_b_x, t_b_y; // b_rect / txt.rect relation

    int x_change =  new_x - button->b_rect.x;
    int y_change = new_y - button->b_rect.y;





    t_b_x = button->txt.rect.x - button->b_rect.x;
    t_b_y = button->txt.rect.y - button->b_rect.y;


    button->b_rect.x += x_change;
    button->b_rect.y += y_change;


    button->rect.x += x_change ;
    button->rect.y += y_change;


    button->txt.rect.x += x_change;
    button->txt.rect.y += y_change;



}


void y_order_buttons(Button *button,int margin , int b_ct)
{
    for(int i=1;i<b_ct;i++)
    {
        printf(" ordering ...%s \n",button[i].txt.writen);
        button[i].txt.rect.y =  button[i-1].txt.rect.y + button[i-1].b_rect.h + margin;
        button[i].b_rect.y = button[i-1].b_rect.y + button[i-1].b_rect.h + margin;
        button[i].rect.y = button[i-1].rect.y + button[i-1].b_rect.h + margin;
    }

}



void x_order_buttons(Button *button,int margin , int b_ct)
{
    for(int i=1;i<b_ct;i++)
    {
        button[i].txt.rect.x = button[i-1].txt.rect.x + button[i-1].b_rect.w + margin;
        button[i].b_rect.x = button[i-1].b_rect.x + button[i-1].b_rect.w + margin;
        button[i].rect.x = button[i-1].rect.x + button[i-1].b_rect.w + margin;
    }
}







