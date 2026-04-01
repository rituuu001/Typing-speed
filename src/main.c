#include<raylib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"../include/typing.h"
#include"../include/common.h"
#include "../include/stats.h"
#include "../include/textloader.h"
Rectangle WPMBOX={800,60,150,75};
Rectangle ACCBOX={1000,60,150,75};
Rectangle TIMERBOX={1200,60,150,75};
Rectangle logoBox = {534, 200, 112, 90};   
void resetGame(char *input, int *inputLength, float *timer, GameStats *stats,float *timemode,int mode, char *target)
{
    input[0]     = '\0';
    *inputLength = 0;
    *timer=*timemode;
    resetStats(stats);  
     loadRandomText(mode, target);
}

int main()
 { 
    srand(time(NULL));
    InitWindow(1440,900,  "TYPING GAME");
    Font font1=LoadFontEx("../assets/Cinzel-Bold.ttf",180, 0, 0);
    Font font2=LoadFontEx("../assets/RobotoMono-Regular.ttf",180, 0, 0);
    Font font3=LoadFontEx("../assets/RobotoMono-Bold.ttf",180, 0, 0);
     Font font4=LoadFontEx("../assets/RobotoMono-ExtraLight.ttf",180, 0, 0);
    Texture2D logo= LoadTexture("../assets/logo.png");
    
    char input[MAX_TEXT_LEN] = "";
    int inputLength=0;
    int framecount=0;
    float timer=0.0f;
    float timemode=0.0f;
    int mode ;
    char target[MAX_TEXT_LEN] ="";
    GameStats stats;
    GAMESCREEN CURRENT_SCREEN=SCREEN_LOAD;
    GAMESCREEN PREVIOUS_SCREEN=SCREEN_LOAD;
     SetTargetFPS(60);
     while (!WindowShouldClose()) {
        int screenChanged = (CURRENT_SCREEN != PREVIOUS_SCREEN);
        PREVIOUS_SCREEN = CURRENT_SCREEN;
        BeginDrawing();
        ClearBackground(BG);
        switch(CURRENT_SCREEN)
        {
            case SCREEN_LOAD:
            {framecount++;
                // top left
            DrawRectangle(16, 16, 20, 2, COLOR1);  // horizontal
            DrawRectangle(16, 16, 2, 20, COLOR1);  // vertical
            // top right
            DrawRectangle(1404, 16, 20, 2, COLOR1);
            DrawRectangle(1422, 16, 2, 20, COLOR1);
            // bottom left
            DrawRectangle(16, 882, 20, 2, COLOR1);
            DrawRectangle(16, 864, 2, 20, COLOR1);
            // bottom right
            DrawRectangle(1404, 882, 20, 2, COLOR1);
            DrawRectangle(1422, 864, 2, 20, COLOR1);
            DrawRectangleRounded(logoBox, 0.3f, 8, COLOR1);
            DrawTextEx(font3, "ts", (Vector2){564, 223}, 45, 2, BG);
            DrawTextEx(font4, "typingspeed", (Vector2){680, 223}, 45,4, COLOR1);
            DrawTextEx(font1, "TYPE", (Vector2){430, 360}, 150, -2, LIGHTGRAY);
            DrawTextEx(font1, "FAST", (Vector2){725, 360}, 150, -2, COLOR1);
            DrawTextEx(font4, "MEASURE YOUR SPEED", (Vector2){470, 530}, 50,5, LIGHT);
            DrawRectangle(620, 630, 200, 2, COLOR1);
            if ((framecount / 30) % 2 == 0)
            DrawTextEx(font2, "press any key to begin", (Vector2){480, 700}, 40, 2, COLOR1);
            float progress = (float)framecount / 600.0f;
            int barWidth = (int)(1440 * progress);
            DrawRectangle(0, 896, barWidth, 4, COLOR1);
            if(framecount>600 || GetKeyPressed())
            CURRENT_SCREEN=SCREEN_MODE;
            }
            break;

            case SCREEN_MODE:
            {
            DrawModeSelectScreen(&CURRENT_SCREEN, font1, font2,font3, &mode,&timemode);
            break;
            }
            case SCREEN_TYPING:
            {if (screenChanged)                              // reset once on entry
                    {resetGame(input, &inputLength, &timer, &stats,&timemode,mode,target);
                        }
           
            DrawTextureEx(logo, (Vector2){20, 22}, 0.0f, 0.1f, WHITE);
            DrawTextEx(font2, "typingSpeed", (Vector2){65, 16}, 50, -2,LIGHTGRAY);
            DrawRectangleRoundedLinesEx(WPMBOX, 0.5f, 64,2.0f,COLOR1);
            DrawRectangleRounded(WPMBOX, 0.5f, 64, COLOR2);
            DrawRectangleRoundedLinesEx(ACCBOX, 0.5f, 64,2.0f,COLOR1);
            DrawRectangleRounded(ACCBOX, 0.5f, 64, COLOR2);
            DrawRectangleRoundedLinesEx(TIMERBOX, 0.5f, 64,2.0f,COLOR1);
            DrawRectangleRounded(TIMERBOX, 0.5f, 64, COLOR2);
            handleTypingInput(input,&inputLength,target,&stats);
            if (inputLength>0)
            {timer-=GetFrameTime();}
            float timetaken=timemode-timer;
            float wpm=calculateWpm(stats.correctChars,timetaken);
            float acc=calculateAccuracy(stats.correctChars, stats.totalChars);
            DrawTextEx(font1, TextFormat("WPM:%d",(int)wpm), (Vector2){815,75},45,-1, LIGHTGRAY);
            DrawTextEx(font1,TextFormat("ACC:%d",(int)acc), (Vector2){1015,75},45,-1, LIGHTGRAY);
            DrawTextEx(font1,TextFormat("TIME:%d",(int)timer), (Vector2){1215,75},45,-1, LIGHTGRAY);
            drawTypingScreen(font2, input, target, &inputLength);
            

            if (isgameover(&inputLength, target, timer)) 
            {
                stats.wpm = wpm;
                stats.accuracy = acc;
                CURRENT_SCREEN = SCREEN_GAMEOVER;      
            }
            }
            break;

            case SCREEN_GAMEOVER:
            {DrawGameOverScreen(&CURRENT_SCREEN, font1, font2, &stats);
                  }
            break;

            case SCREEN_LEADERBOARD:
            {DrawLeaderboardScreen(&CURRENT_SCREEN, font1, font2);
                }
            break;

        }
        
       EndDrawing();
}
    UnloadFont(font1);
    UnloadFont(font2);
    UnloadTexture(logo);
    UnloadFont(font3);
    UnloadFont(font4);
   
    CloseWindow();
    return 0;
}