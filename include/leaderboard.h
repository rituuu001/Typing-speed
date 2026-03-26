#ifndef LEADERBOARD_H
#define LEADERBOARD_H

typedef struct {
    char name[50];
    int wpm;
    float accuracy;
    char mode[20];
} Score;

void saveScore(Score s);
int readScores(Score scores[]);
void sortScoresByWPM(Score scores[], int count);
void displayScores(Score scores[], int count);

#endif
