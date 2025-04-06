//
// Created by lain on 4/3/25.
//

#include "tools.h"

  // For game->width, game->height
/*
SDL_Surface *create_black_surface() {
    SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 800, 600, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
    return surface;
}

SDL_Surface *create_red_surface() {
    SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 800, 600, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));
    return surface;
}

SDL_Surface *create_blue_surface() {
    SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 800, 600, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 255));
    return surface;
}
*/


// random shit we might need
/*
    if (text) {
        SDL_SetAlpha(text, SDL_SRCALPHA, 255);
        printf("Text rendered: %dx%d\n", text->w, text->h);
    } else {
        printf("Text failed: %s\n", TTF_GetError());
    }

*/


SDL_Surface *create_color_surface(int w , int h , Uint8 r, Uint8 g, Uint8 b ) {
    SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE, w,h, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b));
    return surface;

}



// scale surf :


SDL_Surface* scaleSurface(SDL_Surface* surface, int width, int height) {
    SDL_Surface* scaledSurface = SDL_CreateRGBSurface(surface->flags, width, height, surface->format->BitsPerPixel,
                                                      surface->format->Rmask, surface->format->Gmask,
                                                      surface->format->Bmask, surface->format->Amask);
    SDL_SoftStretch(surface, NULL, scaledSurface, NULL);
    return scaledSurface;
}



SDL_Surface *create_blank_surface(int w, int h) {
    SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0, 0, 0, 0);
    if (!surface) {
        printf("SDL_CreateRGBSurface failed: %s\n", SDL_GetError());
        return NULL;
    }

    // Fill with black (arbitrary, since alpha will make it invisible)/
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));

    // Set fully transparent
    SDL_SetAlpha(surface, SDL_SRCALPHA, 0);

    return surface;
}




// change rect1  to center inside rect2
