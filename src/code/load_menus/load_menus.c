//
// Created by lain on 4/10/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "load_menus.h"
#include "../game/game.h"
#include "../tools/tools.h"













int pizza() { return  69;}




Menu play_menu(Game game)
{
    Menu play;


    Init_Menu(&play);




    Init_Menu(&play);




    //custom play_menu
    play.b_ct =4;
    play.txt_ct = 3 ;
    play.t_margine =10;
    play.b_margine = 10;


    // mem aloc
    play.buttonlist = (Button*)malloc(sizeof(Button)*play.b_ct);
    play.txtlist = (Text*)malloc(sizeof(Text)*play.txt_ct);




    //Button names and txts
    char *button_strings[] = {"play","options","help","quit"};
    for (int i = 0; i < play.b_ct; i++)
    {
        play.buttonlist[i] = *create_button(&game,(WIDTH - game.x_button_size)/2,300 ,game.y_button_size,game.x_button_size,button_strings[i],WHITE,1);
    }



    y_order_buttons(play.buttonlist ,play.b_margine,play.b_ct);

    //b_pos_update(&play.buttonlist[4],100 ,100);




    play.txtlist[0] = *create_txt(" M A I N    G A M E ",game.big_main_font,BLACK,20,20);
    play.txtlist[1] = *create_txt("prsented by lain",game.main_font,BLACK,play.txtlist[0].rect.x,play.txtlist[0].rect.y + play.txtlist[0].rect.h + play.t_margine);
    play.txtlist[2] = *create_txt("game logo here",game.main_font,BLACK,game.width - 250 , game.height - 40 - play.t_margine);









    return play;
}




// att to make a new menu
Menu exit_menu(Game game)
{
    Menu new_menu;
    Init_Menu(&new_menu);

    // custom menu (general)
    new_menu.b_ct =2;
    new_menu.txt_ct =1;
    new_menu.t_margine =10; // useless in this case cuz we only have 1 txt
    new_menu.b_margine =250;
    char *button_strings[] = {"no","yes"};



    new_menu.buttonlist = (Button*)malloc(sizeof(Button)*new_menu.b_ct);
    new_menu.txtlist = (Text*)malloc(sizeof(Text)*new_menu.txt_ct);


    for (int i = 0; i < new_menu.b_ct; i++)
    {
        new_menu.buttonlist[i] = *create_button(&game,(WIDTH - game.x_button_size)*5/20,(HEIGHT - game.y_button_size)*3/4 ,game.y_button_size,game.x_button_size,button_strings[i],WHITE,1);
    }


    x_order_buttons(new_menu.buttonlist ,new_menu.b_margine,new_menu.b_ct);


    new_menu.txtlist[0] = *create_txt(" you sure you wanna leave ? ",game.big_main_font,BLACK,WIDTH*1/5,HEIGHT*2/5);


    return new_menu;
}



Menu options_menu(Game game)
{


    Menu new_menu;
    Init_Menu(&new_menu);
    new_menu.background = create_color_surface(game.width,game.height,247,247,166);

    // custom menu (general)
    new_menu.b_ct =3;
    new_menu.txt_ct =1;
    new_menu.t_margine =10; // useless in this case cuz we only have 1 txt
    new_menu.b_margine =25;
    char *button_strings[] = {"volume","fullscreen","return"};



    new_menu.buttonlist = (Button*)malloc(sizeof(Button)*new_menu.b_ct);
    new_menu.txtlist = (Text*)malloc(sizeof(Text)*new_menu.txt_ct);


    for (int i = 0; i < new_menu.b_ct; i++)
    {
        new_menu.buttonlist[i] = *create_button(&game,(WIDTH - game.x_button_size)*5/20,(HEIGHT - game.y_button_size)*3/4 ,game.y_button_size,game.x_button_size,button_strings[i],WHITE,1);
    }


    x_order_buttons(new_menu.buttonlist ,new_menu.b_margine,new_menu.b_ct);


//b_pos_update(&new_menu.buttonlist[2],200,HEIGHT - game.y_button_size);
//
//b_pos_update(&new_menu.buttonlist[1],600,HEIGHT - game.y_button_size);
    //update_txt(&new_menu.buttonlist[1].txt,new_menu.buttonlist[1].txt.writen,BLACK,game.mini_font);


    new_menu.txtlist[0] = *create_txt("controls... ",game.big_main_font,BLACK,WIDTH*2/5,HEIGHT*2/5);


    return new_menu;
}

Menu WIP_menu(Game game)
{



        Menu new_menu;
        Init_Menu(&new_menu);
        new_menu.background = create_color_surface(game.width,game.height,0,0,0);

        // custom menu (general)
        new_menu.b_ct =1;
        new_menu.txt_ct =1;
        new_menu.t_margine =10; // useless in this case cuz we only have 1 txt
        new_menu.b_margine =25;
        char *button_strings[] = {"return"};



        new_menu.buttonlist = (Button*)malloc(sizeof(Button)*new_menu.b_ct);
        new_menu.txtlist = (Text*)malloc(sizeof(Text)*new_menu.txt_ct);


        for (int i = 0; i < new_menu.b_ct; i++)
        {
            new_menu.buttonlist[i] = *create_button(&game,(WIDTH - game.x_button_size)*10/20,(HEIGHT - game.y_button_size)*3/4 ,game.y_button_size,game.x_button_size,button_strings[i],WHITE,1);
        }


        //x_order_buttons(new_menu.buttonlist ,new_menu.b_margine,new_menu.b_ct);


        //b_pos_update(&new_menu.buttonlist[2],200,HEIGHT - game.y_button_size);
        //
        //b_pos_update(&new_menu.buttonlist[1],600,HEIGHT - game.y_button_size);
        //update_txt(&new_menu.buttonlist[1].txt,new_menu.buttonlist[1].txt.writen,BLACK,game.mini_font);


        new_menu.txtlist[0] = *create_txt(" we are still working on this... ",game.big_main_font,WHITE,WIDTH*1/5,HEIGHT*2/5);


        return new_menu;

}









