#include "stats.h"

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