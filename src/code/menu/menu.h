
//
// Created by lain on 4/8/25.
//

#ifndef MENU_H
#define MENU_H


#include "../game/game.h"
#include"../text/txt.h"
#include "../button/button.h"
#include"../Background/background.h"


void Init_Menu(Menu *menu);


void render_menu(Game *game,Menu *menu);


M_node *M_link_Node(Menu* menu,M_node *parent);








#endif //MENU_H
