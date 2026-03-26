#include <stdio.h>
#include <string.h>
#include "leaderboard.h"

void saveScore(Score s)
{
    FILE *fp = fopen("scores.txt","a");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp,"%s %d %.2f %s\n",
            s.name,
            s.wpm,
            s.accuracy,
            s.mode);

    fclose(fp);
}

int readScores(Score scores[])
{
    FILE *fp = fopen("scores.txt","r");
    int count = 0;

    if(fp == NULL)
        return 0;

    while(fscanf(fp,"%s %d %f %s",
          scores[count].name,
          &scores[count].wpm,
          &scores[count].accuracy,
          scores[count].mode) != EOF)
    {
        count++;
    }

    fclose(fp);

    return count;
}

void sortScoresByWPM(Score scores[], int count)
{
    int i,j;
    Score temp;

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

void displayScores(Score scores[], int count)
{
    int i;

    printf("\nLeaderboard:\n");

    for(i=0;i<count;i++)
    {
        printf("%s  WPM:%d  Accuracy:%.2f  Mode:%s\n",
        scores[i].name,
        scores[i].wpm,
        scores[i].accuracy,
        scores[i].mode);
    }
}
