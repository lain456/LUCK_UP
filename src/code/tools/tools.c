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

    // Fill with black (arbitrary, since alpha will make it invisible)
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));

    // Set fully transparent
    SDL_SetAlpha(surface, SDL_SRCALPHA, 0);

    return surface;
}




// center_text_surf -grok
SDL_Surface *create_centered_label(SDL_Rect targetRect, TTF_Font *font, const char *text, SDL_Color color) {
    if (!font || !text || targetRect.w <= 0 || targetRect.h <= 0) {
        printf("Invalid input: font or text is NULL or targetRect has invalid dimensions\n");
        return NULL;
    }

    // Render text with transparency
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text, color);
    if (!textSurface) {
        printf("TTF_RenderText_Blended failed: %s\n", TTF_GetError());
        return NULL;
    }

    // Create a surface with alpha support matching targetRect dimensions
    SDL_Surface *resultSurface = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA,
                                                      targetRect.w,
                                                      targetRect.h,
                                                      32,
                                                      0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
    if (!resultSurface) {
        printf("SDL_CreateRGBSurface failed: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return NULL;
    }

    // Fill with fully transparent background
    SDL_FillRect(resultSurface, NULL, SDL_MapRGBA(resultSurface->format, 0, 0, 0, 0));

    // Center the text on resultSurface
    SDL_Rect destRect = {
        (targetRect.w - textSurface->w) / 2,
        (targetRect.h - textSurface->h) / 2,
        0, 0
    };
    SDL_BlitSurface(textSurface, NULL, resultSurface, &destRect);

    SDL_FreeSurface(textSurface);
    return resultSurface;
}
