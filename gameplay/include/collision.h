//
// Created by lain on 3/13/25.
//

#ifndef COLLISION_H
#define COLLISION_H
#include <SDL/SDL.h>
#include <stdbool.h>

bool hasIntersection(const SDL_Rect *rect1, const SDL_Rect *rect2);
#endif //COLLISION_H
