//
// Created by lain on 3/12/25.
//
#ifndef ENEMY_H
#define ENEMY_H

#include <SDL/SDL.h>
#include <stdbool.h>

#define MAX_ENEMIES 10
#define ENEMY_SIZE 30
#define ENEMY_SPEED 2

typedef struct {
    float x, y;
    bool active;

    SDL_Surface * flying_to_the_right[4];
    SDL_Surface * flying_to_the_left[4];
} Enemy;

void spawnEnemies(Enemy enemies[], int *enemyCount);
void updateEnemies(Enemy enemies[], int enemyCount, int playerX, int playerY);
void renderEnemies(SDL_Surface *screen, Enemy enemies[], int enemyCount);
void checkCollisions(Enemy enemies[], int enemyCount, int playerX, int playerY, int *playerHealth);

#endif // ENEMY_H
