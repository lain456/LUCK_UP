//
// Created by lain on 3/12/25.
//

#ifndef UTILS_H
#define UTILS_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

void toggleFullscreen(SDL_Surface *screen);
void renderStatus(SDL_Surface *screen, int playerHealth, int bulletCount, int playerLevel, TTF_Font *font);

#endif // UTILS_H
