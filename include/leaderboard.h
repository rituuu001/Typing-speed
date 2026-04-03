#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "stats.h"

void saveScore(GameStats s);
int readScores(GameStats scores[]);
void sortScoresByWPM(GameStats scores[], int count);
#endif
