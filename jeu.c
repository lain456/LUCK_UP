#include "jeu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_image.h>

void initSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
}

void fermerSDL() {
    TTF_Quit();
    SDL_Quit();
}

void chargerQuestions(Question questions[], int *nbQuestions) {
    FILE *file = fopen("questions.txt", "r");
    if (!file) {
        printf("Erreur: Fichier questions.txt introuvable.\n");
        exit(1);
    }

    *nbQuestions = 0;
    while (fscanf(file,
                  " %[^\n]\n"
                  " %[^\n]\n"
                  " %[^\n]\n"
                  " %[^\n]\n"
                  " %c\n",
                  questions[*nbQuestions].question,
                  questions[*nbQuestions].reponseA,
                  questions[*nbQuestions].reponseB,
                  questions[*nbQuestions].reponseC,
                  &questions[*nbQuestions].bonneReponse) == 5) {
        (*nbQuestions)++;
        if (*nbQuestions >= MAX_QUESTIONS) break;
    }

    fclose(file);
}

void afficherQuestion(SDL_Surface *screen, TTF_Font *font, Question *q) {
    SDL_Color blanc = {255, 255, 255};
    SDL_Rect pos = {50, 100}; // Décalé vers le bas pour laisser place au score/vies
    SDL_Surface *texteSurface;
    char buffer[100];

    texteSurface = TTF_RenderText_Solid(font, q->question, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &pos);
        SDL_FreeSurface(texteSurface);
    }

    pos.y += 50;
    snprintf(buffer, sizeof(buffer), "A) %s", q->reponseA);
    texteSurface = TTF_RenderText_Solid(font, buffer, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &pos);
        SDL_FreeSurface(texteSurface);
    }

    pos.y += 30;
    snprintf(buffer, sizeof(buffer), "B) %s", q->reponseB);
    texteSurface = TTF_RenderText_Solid(font, buffer, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &pos);
        SDL_FreeSurface(texteSurface);
    }

    pos.y += 30;
    snprintf(buffer, sizeof(buffer), "C) %s", q->reponseC);
    texteSurface = TTF_RenderText_Solid(font, buffer, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &pos);
        SDL_FreeSurface(texteSurface);
    }
}

void initialiseBackground(Background *bg) {
    bg->TabTag[3] = IMG_Load("background4.jpg");
    if (bg->TabTag[3] == NULL) {
        printf("Erreur chargement background4.jpg: %s\n", IMG_GetError());
    }

    bg->TabPos[3].x = 0;
    bg->TabPos[3].y = 0;
    bg->TabPos[3].w = bg->TabTag[3]->w;
    bg->TabPos[3].h = bg->TabTag[3]->h;

    chargerImagesChrono(bg);
}

void chargerImagesChrono(Background *bg) {
    char filename[20];
    for (int i = 0; i < 5; i++) {
        snprintf(filename, sizeof(filename), "t%d.png", i+1);
        bg->chronoImages[i] = IMG_Load(filename);
        if (bg->chronoImages[i] == NULL) {
            printf("Erreur chargement %s: %s\n", filename, IMG_GetError());
        }
    }
    bg->chronoPos.x = 650;
    bg->chronoPos.y = 20;
}

void afficherBackground4(Background *bg, SDL_Surface *screen) {
    if (bg->TabTag[3] != NULL) {
        SDL_BlitSurface(bg->TabTag[3], NULL, screen, &bg->TabPos[3]);
    }
}

void afficherChrono(Background *bg, SDL_Surface *screen, Uint32 tempsEcoule) {
    if (tempsEcoule >= TEMPS_TOTAL) return;

    int imageIndex = tempsEcoule / TEMPS_IMAGE;
    if (imageIndex >= 5) imageIndex = 4;

    if (bg->chronoImages[imageIndex] != NULL) {
        SDL_BlitSurface(bg->chronoImages[imageIndex], NULL, screen, &bg->chronoPos);
    }
}

void afficherScoreVies(SDL_Surface *screen, TTF_Font *font, int score, int vies) {
    SDL_Color blanc = {255, 255, 255};
    SDL_Rect posScore = {50, 20};
    SDL_Rect posVies = {50, 50};
    SDL_Surface *texteSurface;
    char buffer[100];

    snprintf(buffer, sizeof(buffer), "Score: %d", score);
    texteSurface = TTF_RenderText_Solid(font, buffer, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &posScore);
        SDL_FreeSurface(texteSurface);
    }

    snprintf(buffer, sizeof(buffer), "Vies: %d", vies);
    texteSurface = TTF_RenderText_Solid(font, buffer, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &posVies);
        SDL_FreeSurface(texteSurface);
    }
}

void afficherResultatFinal(SDL_Surface *screen, TTF_Font *font, int score, int vies) {
    SDL_Color blanc = {255, 255, 255};
    SDL_Rect pos = {200, 250};
    SDL_Surface *texteSurface;
    char message[100];

    if (vies > 0) {
        snprintf(message, sizeof(message), "Vous avez gagne! Score: %d", score);
    } else {
        snprintf(message, sizeof(message), "Vous avez perdu... Score: %d", score);
    }

    texteSurface = TTF_RenderText_Solid(font, message, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &pos);
        SDL_FreeSurface(texteSurface);
    }
    SDL_Flip(screen);
    SDL_Delay(3000);
}

void afficherMessage(SDL_Surface *screen, TTF_Font *font, const char *message) {
    SDL_Color blanc = {255, 255, 255};
    SDL_Rect pos = {200, 250};
    SDL_Surface *texteSurface = TTF_RenderText_Solid(font, message, blanc);
    if (texteSurface) {
        SDL_BlitSurface(texteSurface, NULL, screen, &pos);
        SDL_FreeSurface(texteSurface);
    }
}
