#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct {
    SDL_Surface* mini_image;
    SDL_Rect mini_position;
    SDL_Surface* player_image;
    SDL_Rect player_position;
    SDL_Rect minimap_player_position;
} Minimap;

void init_minimap(Minimap* m);
void MAJMinimap(SDL_Rect posJoueur, Minimap* m, SDL_Rect camera, int redimensionnement);
void afficher_minimap(Minimap m, SDL_Surface* screen);
void liberer_minimap(Minimap* m);

SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y);
int collisionPP(SDL_Rect player_pos, SDL_Surface* background);

void affichertemps(int temps);
void animerMinimap(Minimap* m);
void animerMinimape(Minimap* m);

#endif
