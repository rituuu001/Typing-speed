#ifndef STATS_H
#define STATS_H

typedef struct{
    int correctChars;      
    int incorrectChars;    
    int totalChars;        
    float timeTaken;       
    float wpm;             
    float accuracy;        
    char mode[16];         
} GameStats;

float calculateWpm(int correctChars, float timeTaken);
float calculateAccuracy(int correctChars, int totalChars);

#endif