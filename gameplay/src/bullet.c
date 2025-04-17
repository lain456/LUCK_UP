//
// Created by lain on 3/12/25.
//

#include"../../gameplay/include/game.h"
#include "../../gameplay/include/player.h"
#include "../../gameplay/include/bullet.h"
#include "../../gameplay/include/enemy.h"
#include "../../gameplay/include/utils.h"
#include "../../gameplay/include/collision.h" // Include collision.h




#include <math.h>
#include <SDL/SDL.h>

// Remove the definition of hasIntersection
// bool hasIntersection(const SDL_Rect *rect1, const SDL_Rect *rect2) { ... }

void shootBullet(Bullet bullets[], int *bulletCount, int mouseX, int mouseY, int centerX, int centerY) {
    if (*bulletCount < MAX_BULLETS) {
        Bullet *bullet = &bullets[*bulletCount];
        bullet->x = centerX;
        bullet->y = centerY;
        float angle = atan2(mouseY - centerY, mouseX - centerX);
        bullet->vx = cos(angle) * 5;
        bullet->vy = sin(angle) * 5;
        bullet->active = true;
        (*bulletCount)++;
    }
}

void updateBullets(Bullet bullets[], int *bulletCount, Enemy enemies[], int enemyCount) {
    for (int i = 0; i < *bulletCount; i++) {
        if (bullets[i].active) {
            bullets[i].x += bullets[i].vx;
            bullets[i].y += bullets[i].vy;
            if (bullets[i].x < 0 || bullets[i].x > 800 || bullets[i].y < 0 || bullets[i].y > 600) {
                bullets[i].active = false;
            } else {
                // Check for collisions with enemies
                SDL_Rect bulletRect = { (int)bullets[i].x, (int)bullets[i].y, 5, 5 };
                for (int j = 0; j < enemyCount; j++) {
                    if (enemies[j].active) {
                        SDL_Rect enemyRect = { (int)enemies[j].x, (int)enemies[j].y, ENEMY_SIZE, ENEMY_SIZE };
                        if (hasIntersection(&bulletRect, &enemyRect)) {
                            bullets[i].active = false;
                            enemies[j].active = false;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void renderBullets(SDL_Surface *screen, Bullet bullets[], int bulletCount) {
    SDL_Rect bulletRect;
    for (int i = 0; i < bulletCount; i++) {
        if (bullets[i].active) {
            bulletRect.x = (int)bullets[i].x;
            bulletRect.y = (int)bullets[i].y;
            bulletRect.w = 5;
            bulletRect.h = 5;
            SDL_FillRect(screen, &bulletRect, SDL_MapRGB(screen->format, 255, 255, 255));
        }
    }
}
