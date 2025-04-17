/*


#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include"../../gameplay/include/game.h"
#include "../../gameplay/include/player.h"
#include "../../gameplay/include/bullet.h"
#include "../../gameplay/include/enemy.h"
#include "../../gameplay/include/utils.h"
#include "../../gameplay/include/collision.h"




int displayMenu(SDL_Surface *screen, TTF_Font *font) {
    SDL_Surface *menuSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, 800, 600, 32, 0, 0, 0, 0);
    SDL_FillRect(menuSurface, NULL, SDL_MapRGB(menuSurface->format, 0, 0, 0));

    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Play Again?", textColor);
    SDL_Rect dstRect = { 300, 250, textSurface->w, textSurface->h };
    SDL_BlitSurface(textSurface, NULL, menuSurface, &dstRect);
    SDL_FreeSurface(textSurface);

    SDL_Rect yesRect = { 300, 350, 100, 50 };
    SDL_Rect noRect = { 400, 350, 100, 50 };

    SDL_FillRect(menuSurface, &yesRect, SDL_MapRGB(menuSurface->format, 0, 255, 0));
    SDL_FillRect(menuSurface, &noRect, SDL_MapRGB(menuSurface->format, 255, 0, 0));

    textSurface = TTF_RenderText_Solid(font, "Yes", textColor);
    dstRect = (SDL_Rect){ 325, 360, textSurface->w, textSurface->h };
    SDL_BlitSurface(textSurface, NULL, menuSurface, &dstRect);
    SDL_FreeSurface(textSurface);

    textSurface = TTF_RenderText_Solid(font, "No", textColor);
    dstRect = (SDL_Rect){ 425, 360, textSurface->w, textSurface->h };
    SDL_BlitSurface(textSurface, NULL, menuSurface, &dstRect);
    SDL_FreeSurface(textSurface);

    SDL_BlitSurface(menuSurface, NULL, screen, NULL);
    SDL_Flip(screen);
    SDL_FreeSurface(menuSurface);

    SDL_Event e;
    while (1) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return 0;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                if (mouseX >= yesRect.x && mouseX <= yesRect.x + yesRect.w &&
                    mouseY >= yesRect.y && mouseY <= yesRect.y + yesRect.h) {
                    return 1; // Yes
                } else if (mouseX >= noRect.x && mouseX <= noRect.x + noRect.w &&
                           mouseY >= noRect.y && mouseY <= noRect.y + noRect.h) {
                    return 0; // No
                }
            }
        }
    }
}




int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("../ttf/fredoka-one.one-regular.ttf", 24);
    if (font == NULL) {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Surface *screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        printf("SDL_SetVideoMode Error: %s\n", SDL_GetError());
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    Player player;
    initPlayer(&player);

    Bullet bullets[MAX_BULLETS] = {0};
    int bulletCount = 0;

    Enemy enemies[MAX_ENEMIES] = {0};
    int enemyCount = 0;
    spawnEnemies(enemies, &enemyCount);
    SDL_Event e;
    int quit = 0;
    int mouseX, mouseY;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mouseX, &mouseY);
                shootBullet(bullets, &bulletCount, mouseX, mouseY, player.x + SQUARE_SIZE / 2, player.y + SQUARE_SIZE / 2);
            } else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
                handlePlayerMovement(&player, e);
                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_f && (SDL_GetModState() & KMOD_CTRL)) {
                    toggleFullscreen(screen);
                } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                    int playAgain = displayMenu(screen, font);
                    if (playAgain == 0) {
                        quit = 1;
                    } else {
                        // Reset game state
                        initPlayer(&player);
                        bulletCount = 0;
                        enemyCount = 0;
                        for (int i = 0; i < MAX_ENEMIES; i++) {
                            enemies[i].active = false;
                        }
                        //spawnEnemies(enemies, &enemyCount);
                    }
                }
            }
        }

        updatePlayer(&player);
        updateBullets(bullets, &bulletCount, enemies, enemyCount);
        updateEnemies(enemies, enemyCount, player.x, player.y);
        checkCollisions(enemies, enemyCount, player.x, player.y, &player.health);

        // Level up when enemies die
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemies[i].active) {
                player.level++;
                enemies[i].active = true;
                enemies[i].x = rand() % 800;
                enemies[i].y = rand() % 600;
            }
        }

        if (player.health <= 0) {
            int playAgain = displayMenu(screen, font);
            if (playAgain == 0) {
                quit = 1;
            } else {
                // Reset game state
                initPlayer(&player);
                bulletCount = 0;
                enemyCount = 0;
                for (int i = 0; i < MAX_ENEMIES; i++) {
                    enemies[i].active = false;
                }
                spawnEnemies(enemies, &enemyCount);
            }
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        renderPlayer(screen, &player);
        renderBullets(screen, bullets, bulletCount);
        renderEnemies(screen, enemies, enemyCount);
        renderStatus(screen, player.health, bulletCount, player.level, font);

        SDL_Flip(screen);

        SDL_Delay(16);
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}




*/