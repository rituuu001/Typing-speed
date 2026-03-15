#ifndef TYPING_H
#define TYPING_H
#include"stats.h"
#include<raylib.h>


void drawTypingScreen(Font font,char *input,char *target,int *inputLength);
void handleTypingInput(char *input, int *inputLength, char *target,GameStats *s);
int isgameover(int *inputLength,char * target,float timer); 

#endif