#ifndef COMMON_H
#define COMMON_H
#include <raylib.h>
// color theme
#define COLOR1 (Color){158, 114, 195, 255}
#define COLOR2 (Color){158, 114, 195, 35}
#define BG     (Color){26, 32, 44, 255}
#define LIGHT  (Color){180, 200, 200, 60}
#define WRONG_COLOR   (Color){255, 80, 80, 255}   // red for wrong
#define MODE_SENTENCE  1
#define MODE_PARAGRAPH 2
typedef enum
{
    SCREEN_LOAD,
    SCREEN_MODE,
    SCREEN_TYPING,
    SCREEN_GAMEOVER,
    SCREEN_LEADERBOARD
}GAMESCREEN;
#endif

