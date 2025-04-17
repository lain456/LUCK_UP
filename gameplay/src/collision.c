//
// Created by lain on 3/13/25.
//
#include <stdio.h>


#include "../../gameplay/include/collision.h"
#include <SDL/SDL.h>
#include <stdbool.h>

bool hasIntersection(const SDL_Rect *rect1, const SDL_Rect *rect2) {
    return !(rect2->x > (rect1->x + rect1->w) ||
             (rect2->x + rect2->w) < rect1->x ||
             rect2->y > (rect1->y + rect1->h) ||
             (rect2->y + rect2->h) < rect1->y);
}