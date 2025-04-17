//
// Created by lain on 3/12/25.
//

#ifndef BULLET_H
#define BULLET_H

#include <SDL/SDL.h>
#include <stdbool.h>
#include "enemy.h"

#define MAX_BULLETS 100

typedef struct {
    float x, y;
    float vx, vy;
    bool active;
} Bullet;

void shootBullet(Bullet bullets[], int *bulletCount, int mouseX, int mouseY, int centerX, int centerY);
void updateBullets(Bullet bullets[], int *bulletCount, Enemy enemies[], int enemyCount);
void renderBullets(SDL_Surface *screen, Bullet bullets[], int bulletCount);

#endif // BULLET_H