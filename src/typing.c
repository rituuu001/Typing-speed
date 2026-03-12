
#include <raylib.h>
#include "../include/typing.h"
#include"../include/common.h"
#include <string.h>
#include<stdio.h>

void drawTypingScreen(Font font)
{
    char* target = "the quick brown fox jumps over the lazy dog";
    char* input = "the quick brow";
    int inputLength = 14;
    float StartX=20;
    float StartY=200;
    float x=StartX,y=StartY;
    float maxX=1380;
    Vector2 charSize= MeasureTextEx(font,"a",60,3);
    Color colour;
  //handles the multiline display in screen
    for(int i=0;target[i]!='\0';i++)
    { char letter[2] = {target[i], '\0'};
      DrawTextEx(font,letter,(Vector2){x,y},60,3,LIGHT);
      x+=charSize.x;
      if (x>maxX)
      {
        x=StartX;
        y+=charSize.y+10;
      }}
      x=StartX;y=StartY;
      for(int i=0;target[i]!='\0';i++)
    { char letter[2] = {target[i], '\0'};
      if (i<inputLength)
      {
        colour=(input[i]==target[i])?WHITE:WRONG_COLOR;
        DrawTextEx(font,letter,(Vector2){x,y},60,3,colour);
      }
        x+=charSize.x;
         if (x>maxX)
      {
        x=StartX;
        y+=charSize.y+10;
      }
      }
    }

