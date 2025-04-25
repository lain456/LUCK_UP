#ifndef JEU_H
#define JEU_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define MAX_QUESTIONS 10
#define TEMPS_TOTAL 30000
#define TEMPS_IMAGE 6000
#define SCORE_BONUS_2 1000
#define SCORE_BONUS_3 3000
#define VIES_INITIALES 3

typedef struct {
    char question[100];
    char reponseA[30];
    char reponseB[30];
    char reponseC[30];
    char bonneReponse;
} Question;

typedef struct {
    SDL_Surface *TabTag[5];
    SDL_Rect TabPos[5];
    SDL_Surface *chronoImages[5];
    SDL_Rect chronoPos;
} Background;

void initSDL();
void fermerSDL();
void chargerQuestions(Question questions[], int *nbQuestions);
void afficherQuestion(SDL_Surface *screen, TTF_Font *font, Question *q);
void initialiseBackground(Background *bg);
void afficherBackground4(Background *bg, SDL_Surface *screen);
void afficherResultatFinal(SDL_Surface *screen, TTF_Font *font, int score, int vies);
void chargerImagesChrono(Background *bg);
void afficherChrono(Background *bg, SDL_Surface *screen, Uint32 tempsEcoule);
void afficherMessage(SDL_Surface *screen, TTF_Font *font, const char *message);
void afficherScoreVies(SDL_Surface *screen, TTF_Font *font, int score, int vies);

#endif
