//
// Created by lain on 3/12/25.
//



#include "../../gameplay/include/utils.h"


#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

void toggleFullscreen(SDL_Surface *screen) {
    Uint32 flags = screen->flags;
    if (flags & SDL_FULLSCREEN) {
        SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
    } else {
        SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE | SDL_FULLSCREEN);
    }
}

void renderStatus(SDL_Surface *screen, int playerHealth, int bulletCount, int playerLevel, TTF_Font *font) {
    char status[50];
    sprintf(status, "Health: %d  Bullets: %d  Level: %d", playerHealth, bulletCount, playerLevel);

    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, status, textColor);
    SDL_Rect dstRect = { 10, 10, textSurface->w, textSurface->h };
    SDL_BlitSurface(textSurface, NULL, screen, &dstRect);
    SDL_FreeSurface(textSurface);

    // Render health bar
    SDL_Rect healthBar = { 10, 70, playerHealth * 20, 20 }; // Assuming max health is 10
    SDL_FillRect(screen, &healthBar, SDL_MapRGB(screen->format, 255, 0, 0));
}