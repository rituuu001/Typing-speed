#include <stdio.h>
#include <string.h>
#include "leaderboard.h"
#include "stats.h"


void saveScore(GameStats s)
{
    FILE *fp = fopen("scores.txt","a");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp,"%s %f %.2f\n",
            s.name,
            s.wpm,
            s.accuracy
            );

    fclose(fp);
}

int readScores(GameStats scores[])
{
    FILE *fp = fopen("scores.txt","r");
    int count = 0;

    if(fp == NULL)
        return 0;

    while(fscanf(fp,"%s %f %f",
      scores[count].name,
      &scores[count].wpm,
      &scores[count].accuracy) == 3)
{
    count++;
}

    fclose(fp);

    return count;
}

void sortScoresByWPM(GameStats scores[], int count)
{
    int i,j;
    GameStats temp;

    for(i=0;i<count-1;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(scores[j].wpm > scores[i].wpm)
            {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
}

void displayScores(GameStats scores[], int count)
{
    int i;

    printf("\nLeaderboard:\n");

    for(i=0;i<count;i++)
    {
        printf("%s  WPM:%f  Accuracy:%.2f  Mode:%s\n",
        scores[i].name,
        scores[i].wpm,
        scores[i].accuracy,
        scores[i].mode);
    }
}
