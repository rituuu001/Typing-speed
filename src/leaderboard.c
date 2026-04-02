#include <stdio.h>
#include <string.h>
#include "leaderboard.h"
#include "stats.h"

//save scores to the file "scores.txt"
void saveScore(GameStats s)
{
    FILE *fp = fopen("../assets/scores.txt","a");
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
//read saved scores 
int readScores(GameStats scores[])
{
    FILE *fp = fopen("../assets/scores.txt","r");
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
//Sorts the name of users on the basis of wpm
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
