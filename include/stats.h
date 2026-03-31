#ifndef STATS_H
#define STATS_H
#include<raylib.h>
#include"common.h"

typedef struct{
    int correctChars;      
    int incorrectChars;    
    int totalChars;        
    float timeTaken;       
    float wpm;             
    float accuracy;        
    char mode[16];
    char name[50];
} GameStats;

float calculateWpm(int correctChars, float timeTaken);
float calculateAccuracy(int correctChars, int totalChars);
void  updateStats(GameStats *s, char expected, char typed);
void  resetStats(GameStats *s);

void DrawModeSelectScreen(GAMESCREEN *currentScreen, Font font1, Font font2, Font font3, int *mode,float *timemode);
void DrawGameOverScreen(GAMESCREEN *currentScreen, Font font1, Font font2, GameStats *stats);
void DrawLeaderboardScreen(GAMESCREEN *currentScreen, Font font1, Font font2);

#endif
