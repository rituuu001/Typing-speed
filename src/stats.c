#include "../include/stats.h"


float calculateWpm(int correctChars, float timeTaken)
{
    if (timeTaken <=0 )
    {
    return 0;
    }
    float minutes = timeTaken/60.0f;
    float words = correctChars/5.0f;
    return words/minutes;
}

float calculateAccuracy(int correctChars, int totalChars)
{
    if (totalChars <= 0)
    {
    return 0;
    }
    return ((float)correctChars/(float)totalChars)*100.0f;
}
void updateStats(GameStats *s, char expected, char typed) {
    s->totalChars++;
    if (typed == expected)
        s->correctChars++;
    else
        s->incorrectChars++;
}

void resetStats(GameStats *s) {
    s->correctChars   = 0;
    s->incorrectChars = 0;
    s->totalChars     = 0;
    s->timeTaken      = 0.0f;
    s->wpm            = 0.0f;
    s->accuracy       = 0.0f;
    s->mode[0]        = '\0';
}