
#include <raylib.h>
#include "../include/typing.h"
#include"../include/common.h"
#include "../include/stats.h"
#include <string.h>
#include<stdio.h>

void drawTypingScreen(Font font,char *input,char *target,int *inputLength)
{
    float StartX=20;
    float StartY=300;
    float x=StartX,y=StartY;
    float maxX=1380;
    Vector2 charSize= MeasureTextEx(font,"a",60,3);
    Color colour;
      for(int i=0;target[i]!='\0';i++)
    { char letter[2] = {target[i], '\0'};
      if (i<(*inputLength))
      {
        colour=(input[i]==target[i])?WHITE:WRONG_COLOR;
        DrawTextEx(font,letter,(Vector2){x,y},60,3,colour);
      }
      if (i>(*inputLength))
      {
        DrawTextEx(font,letter,(Vector2){x,y},60,3,LIGHT);

      }
      if (i==(*inputLength))
      {
        DrawRectangle(x,y,5,charSize.y,COLOR1);
        DrawTextEx(font,letter,(Vector2){x,y},60,3,LIGHT);
      }
        x+=charSize.x;
         if (x>maxX)
      {
        x=StartX;
        y+=charSize.y+10;
      }
      }}

    void handleTypingInput(char *input, int *inputLength, char *target,GameStats *s)
    {
    int key = GetCharPressed();
    //stores the input characters in the array input[]
    while (key >= 32 && key <= 126) {
        if (*inputLength < (int)strlen(target)) {
            input[*inputLength] = (char)key;
            updateStats(s, target[*inputLength], input[*inputLength]);
            (*inputLength)++;
            input[*inputLength] = '\0';
        }
        key = GetCharPressed();
    }
    //backspace handling to delete characters or the entire word
   if ((IsKeyPressed(KEY_LEFT_CONTROL)||IsKeyPressed(KEY_RIGHT_CONTROL)) && IsKeyPressed(KEY_BACKSPACE))
   {while(*inputLength>0 && input[(*inputLength)-1]==' ')
   {
    (*inputLength)--;
     if (input[*inputLength]==target[*inputLength])
    s->correctChars--;
    else
    s->incorrectChars--;
    input[*inputLength]='\0';
    s->totalChars--; 
   }
   while(*inputLength>0 && input[(*inputLength)-1]!=' ')
   {
    (*inputLength)--;
     if (input[*inputLength]==target[*inputLength])
    s->correctChars--;
    else
    s->incorrectChars--;
    input[*inputLength]='\0';
    s->totalChars--;
   }}
   else if (IsKeyPressed(KEY_BACKSPACE) && (*inputLength)>0)
   {
    (*inputLength)--;
     if (input[*inputLength]==target[*inputLength])
    s->correctChars--;
    else
    s->incorrectChars--;
    input[*inputLength]='\0';
    s->totalChars--;
   }
  }
  int isgameover(int *inputLength,char * target,float timer)
  {
    if ((*inputLength>=(int)strlen(target))||timer<=0.0f)
     return 1;
    else
    return 0;
  }
 
