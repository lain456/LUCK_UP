#include "jeu.h"
#include <stdlib.h>
#include <time.h>

int main() {
    SDL_Surface *screen = NULL;
    Background bg;

    srand(time(NULL));

    Question questions[MAX_QUESTIONS];
    int nbQuestions = 0;
    int score = 0;
    int vies = VIES_INITIALES;
    int bonnesReponsesConsecutives = 0;
    int mauvaisesReponsesConsecutives = 0;

    initSDL();
    chargerQuestions(questions, &nbQuestions);

    screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
    if (!screen) {
        printf("Erreur: Impossible d'ouvrir la fenêtre SDL.\n");
        return 1;
    }

    initialiseBackground(&bg);
    
    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);
    if (!font) {
        printf("Erreur: Impossible de charger la police.\n");
        return 1;
    }

    // Mélange des questions
    int ordreQuestions[MAX_QUESTIONS];
    for (int i = 0; i < nbQuestions; i++) ordreQuestions[i] = i;
    for (int i = nbQuestions - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = ordreQuestions[i];
        ordreQuestions[i] = ordreQuestions[j];
        ordreQuestions[j] = temp;
    }

    int questionsAffichees[MAX_QUESTIONS] = {0};
    int continuer = 1;
    SDL_Event event;
    int indexQuestion = 0;
    Uint32 tempsDebut = SDL_GetTicks();

    // Écran initial
    afficherBackground4(&bg, screen);
    afficherChrono(&bg, screen, 0);
    afficherScoreVies(screen, font, score, vies);
    SDL_Flip(screen);
    SDL_Delay(2000);

    while (continuer && indexQuestion < nbQuestions && vies > 0) {
        Uint32 tempsActuel = SDL_GetTicks();
        Uint32 tempsEcoule = tempsActuel - tempsDebut;

        if (tempsEcoule >= TEMPS_TOTAL) {
            afficherBackground4(&bg, screen);
            afficherMessage(screen, font, "Temps ecoule!");
            SDL_Flip(screen);
            SDL_Delay(2000);
            break;
        }

        int questionCourante = ordreQuestions[indexQuestion];
        
        if (questionsAffichees[questionCourante]) {
            indexQuestion++;
            continue;
        }

        Question q = questions[questionCourante];

        // Affichage
        afficherBackground4(&bg, screen);
        afficherQuestion(screen, font, &q);
        afficherChrono(&bg, screen, tempsEcoule);
        afficherScoreVies(screen, font, score, vies);
        SDL_Flip(screen);

        int repondu = 0;
        while (!repondu && continuer && vies > 0 && (SDL_GetTicks() - tempsDebut) < TEMPS_TOTAL) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    continuer = 0;
                }
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    char reponseUtilisateur = '\0';

                    if (event.button.button == SDL_BUTTON_LEFT) reponseUtilisateur = 'a';
                    else if (event.button.button == SDL_BUTTON_MIDDLE) reponseUtilisateur = 'b';
                    else if (event.button.button == SDL_BUTTON_RIGHT) reponseUtilisateur = 'c';

                    if (reponseUtilisateur == q.bonneReponse) {
                        bonnesReponsesConsecutives++;
                        mauvaisesReponsesConsecutives = 0;
                        
                        // Bonus pour réponses consécutives
                        if (bonnesReponsesConsecutives == 2) {
                            score += SCORE_BONUS_2;
                        } else if (bonnesReponsesConsecutives == 3) {
                            score += SCORE_BONUS_3;
                            bonnesReponsesConsecutives = 0; // Reset après bonus
                        }
                        
                        printf("Bonne réponse ! Score: %d\n", score);
                    } else {
                        mauvaisesReponsesConsecutives++;
                        bonnesReponsesConsecutives = 0;
                        
                        // Perte de vie après 2 mauvaises réponses consécutives
                        if (mauvaisesReponsesConsecutives >= 2) {
                            vies--;
                            mauvaisesReponsesConsecutives = 0;
                            printf("Perte d'une vie! Vies restantes: %d\n", vies);
                        }
                        
                        printf("Mauvaise réponse...\n");
                    }

                    questionsAffichees[questionCourante] = 1;
                    repondu = 1;
                }
            }
        }

        indexQuestion++;
    }

    // Résultat final
    afficherBackground4(&bg, screen);
    afficherResultatFinal(screen, font, score, vies);

    // Nettoyage
    for (int i = 0; i < 5; i++) {
        if (bg.chronoImages[i] != NULL) {
            SDL_FreeSurface(bg.chronoImages[i]);
        }
    }
    if (bg.TabTag[3] != NULL) {
        SDL_FreeSurface(bg.TabTag[3]);
    }
    TTF_CloseFont(font);
    fermerSDL();
    
    return 0;
}
