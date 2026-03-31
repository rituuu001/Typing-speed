#ifndef LEADERBOARD_H
#define LEADERBOARD_H

typedef struct {
    int correctChars;
    int incorrectChars;
    int totalChars;
    float timeTaken;
    float wpm;
    float accuracy;
    char mode[16];
} GameStats;

void saveScore(Score s);
int readScores(Score scores[]);
void sortScoresByWPM(Score scores[], int count);
void displayScores(Score scores[], int count);

#endif
