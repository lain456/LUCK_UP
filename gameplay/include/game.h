//
// Created by lain on 3/14/25.
//

#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "enemy.h"

typedef struct {
    int h;
    int w;
    int fullscreen; //1 for fullscreen, 0 for windowed
    float music_vol;

    Player *player;


    int enemy_count;
    Enemy *enemies;






}Game;

#endif //GAME_H
