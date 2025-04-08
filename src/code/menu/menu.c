//
// Created by lain on 4/8/25.
//

#include "menu.h"





void render_menu(Game *game,Menu *menu)
{
 // just show all buttons and texts
 render_buttons(game,menu->buttonlist,menu->b_ct);
 render_textlist(game,menu->txtlist,menu->txt_ct);
}