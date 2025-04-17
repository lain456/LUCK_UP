//
// Created by lain on 3/12/25.
//

#include "../../gameplay/include/player.h"

#include "../../gameplay/include/enemy.h"

#include "../../gameplay/include/collision.h"
// Include collision.h
#include <math.h>
#include <SDL/SDL.h>

// Remove the definition of hasIntersection
// bool hasIntersection(const SDL_Rect *rect1, const SDL_Rect *rect2) { ... }

void spawnEnemies(Enemy enemies[], int *enemyCount) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) {
            enemies[i].x = rand() % 800;
            enemies[i].y = rand() % 600;
            enemies[i].active = true;
            (*enemyCount)++;
        }
    }
}

void updateEnemies(Enemy enemies[], int enemyCount, int playerX, int playerY) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemies[i].active) {
            float angle = atan2(playerY - enemies[i].y, playerX - enemies[i].x);
            enemies[i].x += cos(angle) * ENEMY_SPEED;
            enemies[i].y += sin(angle) * ENEMY_SPEED;
        }
    }
}

void renderEnemies(SDL_Surface *screen, Enemy enemies[], int enemyCount) {
    SDL_Rect enemyRect;
    for (int i = 0; i < enemyCount; i++) {
        if (enemies[i].active) {
            enemyRect.x = (int)enemies[i].x;
            enemyRect.y = (int)enemies[i].y;
            enemyRect.w = ENEMY_SIZE;
            enemyRect.h = ENEMY_SIZE;
            SDL_FillRect(screen, &enemyRect, SDL_MapRGB(screen->format, 255, 255, 0));
        }
    }
}

void checkCollisions(Enemy enemies[], int enemyCount, int playerX, int playerY, int *playerHealth) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemies[i].active) {
            SDL_Rect enemyRect = { (int)enemies[i].x, (int)enemies[i].y, ENEMY_SIZE, ENEMY_SIZE };
            SDL_Rect playerRect = { playerX, playerY, SQUARE_SIZE, SQUARE_SIZE };
            if (hasIntersection(&enemyRect, &playerRect)) {
                enemies[i].active = false;
                (*playerHealth)--;
            }
        }
    }
}