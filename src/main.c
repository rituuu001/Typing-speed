
#include<raylib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define COLOR1 (Color){158, 114, 195, 255}
#define COLOR2 (Color){158, 114, 195, 35}
#define BG (Color){26, 32, 44, 255}
#define LIGHT (Color){180, 200, 200,50}

Rectangle WPMBOX={800,60,150,75};
Rectangle ACCBOX={1000,60,150,75};
Rectangle TIMERBOX={1200,60,150,75};

   
int main()
 { 
    srand(time(NULL));
    InitWindow(1440,900,  "TYPING GAME");
    SetTargetFPS(60);
    Font font1=LoadFontEx("projectc\\assets\\Cinzel-Bold.ttf",60, 0, 0);
    Font font2=LoadFontEx("projectc\\assets\\RobotoMono-Regular.ttf",60, 0, 0);
    Texture2D logo= LoadTexture("projectc\\assets\\logo.png");
     char *testText = "The quick brown fox jumps over the lazy dog.\n ";
     
    
     
     while (!WindowShouldClose()) {
       
        
        BeginDrawing();
        ClearBackground(BG);
        DrawTextureEx(logo, (Vector2){20, 22}, 0.0f, 0.1f, WHITE);
        DrawTextEx(font2, "typingSpeed", (Vector2){65, 16}, 50, -2,LIGHTGRAY);
        DrawRectangleRoundedLinesEx(WPMBOX, 0.5f, 64,2.0f,COLOR1);
        DrawRectangleRounded(WPMBOX, 0.5f, 64, COLOR2);
        DrawRectangleRoundedLinesEx(ACCBOX, 0.5f, 64,2.0f,COLOR1);
        DrawRectangleRounded(ACCBOX, 0.5f, 64, COLOR2);
        DrawRectangleRoundedLinesEx(TIMERBOX, 0.5f, 64,2.0f,COLOR1);
        DrawRectangleRounded(TIMERBOX, 0.5f, 64, COLOR2);
        DrawTextEx(font1, "WPM:55", (Vector2){815,75},45,-1, LIGHTGRAY);
        DrawTextEx(font1, "ACC:99", (Vector2){1015,75},45,-1, LIGHTGRAY);
        DrawTextEx(font1, "TIME:25", (Vector2){1215,75},45,-1, LIGHTGRAY);
        DrawTextEx(font2, testText, (Vector2){20, 400}, 65, 2.5, LIGHT);
       
       EndDrawing();
}
    UnloadFont(font1);
    UnloadFont(font2);
    UnloadTexture(logo);
   
    CloseWindow();
    return 0;
}