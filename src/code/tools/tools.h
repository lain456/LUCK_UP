//
// Created by lain on 4/3/25.
//

#ifndef TOOLS_H
#define TOOLS_H
#include "../game/game.h"


// functions :
SDL_Surface *create_color_surface(int w , int h , Uint8 r, Uint8 g, Uint8 b );


SDL_Surface* scaleSurface(SDL_Surface* surface, int width, int height);


#endif //TOOLS_H

