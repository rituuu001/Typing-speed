#include "../include/stats.h"


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
void updateStats(GameStats *s, char expected, char typed) {
    s->totalChars++;
    if (typed == expected)
        s->correctChars++;
    else
        s->incorrectChars++;
}

void resetStats(GameStats *s) {
    s->correctChars   = 0;
    s->incorrectChars = 0;
    s->totalChars     = 0;
    s->timeTaken      = 0.0f;
    s->wpm            = 0.0f;
    s->accuracy       = 0.0f;
    s->mode[0]        = '\0';
}

void DrawModeSelectScreen(GAMESCREEN *currentScreen, Font font1, Font font2, int *mode) {
    
    // Title
    DrawTextEx(font1, "SELECT MODE", (Vector2){480, 250}, 80, -2, LIGHTGRAY);
    DrawTextEx(font2, "choose your typing mode", (Vector2){490, 360}, 35, 2, LIGHT);

    // Sentence button
    Rectangle sentenceBtn = {350, 450, 280, 90};
    DrawRectangleRounded(sentenceBtn, 0.5f, 64, COLOR2);
    DrawRectangleRoundedLinesEx(sentenceBtn, 0.5f, 64, 2.0f, COLOR1);
    DrawTextEx(font2, "SENTENCE", (Vector2){410, 478}, 38, 2, COLOR1);

    // Paragraph button
    Rectangle paragraphBtn = {800, 450, 280, 90};
    DrawRectangleRounded(paragraphBtn, 0.5f, 64, COLOR2);
    DrawRectangleRoundedLinesEx(paragraphBtn, 0.5f, 64, 2.0f, COLOR1);
    DrawTextEx(font2, "PARAGRAPH", (Vector2){850, 478}, 38, 2, COLOR1);

    // Check clicks
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, sentenceBtn)) {
            *mode = MODE_SENTENCE;
            *currentScreen = SCREEN_TYPING;
        }
        if (CheckCollisionPointRec(mouse, paragraphBtn)) {
            *mode = MODE_PARAGRAPH;
            *currentScreen = SCREEN_TYPING;
        }
    }
}

void DrawGameOverScreen(GAMESCREEN *currentScreen, Font font1, Font font2, GameStats *stats) {
    
    // Title
    DrawTextEx(font1, "GAME OVER", (Vector2){480, 150}, 100, -2, COLOR1);

    // Stats display
    DrawTextEx(font2, TextFormat("WPM: %d", (int)stats->wpm), (Vector2){560, 320}, 50, 2, LIGHTGRAY);
    DrawTextEx(font2, TextFormat("ACCURACY: %.1f%%", stats->accuracy), (Vector2){560, 390}, 50, 2, LIGHTGRAY);
    DrawTextEx(font2, TextFormat("CORRECT: %d", stats->correctChars), (Vector2){560, 460}, 50, 2, LIGHTGRAY);
    DrawTextEx(font2, TextFormat("INCORRECT: %d", stats->incorrectChars), (Vector2){560, 530}, 50, 2, LIGHTGRAY);

    // Retry button
    Rectangle retryBtn = {400, 650, 200, 70};
    DrawRectangleRounded(retryBtn, 0.5f, 64, COLOR2);
    DrawRectangleRoundedLinesEx(retryBtn, 0.5f, 64, 2.0f, COLOR1);
    DrawTextEx(font2, "RETRY", (Vector2){450, 670}, 35, 2, COLOR1);

    // Menu button
    Rectangle menuBtn = {700, 650, 200, 70};
    DrawRectangleRounded(menuBtn, 0.5f, 64, COLOR2);
    DrawRectangleRoundedLinesEx(menuBtn, 0.5f, 64, 2.0f, COLOR1);
    DrawTextEx(font2, "MENU", (Vector2){755, 670}, 35, 2, COLOR1);

    // Leaderboard button
    Rectangle lbBtn = {1000, 650, 280, 70};
    DrawRectangleRounded(lbBtn, 0.5f, 64, COLOR2);
    DrawRectangleRoundedLinesEx(lbBtn, 0.5f, 64, 2.0f, COLOR1);
    DrawTextEx(font2, "LEADERBOARD", (Vector2){1015, 670}, 35, 2, COLOR1);

    // Check clicks
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, retryBtn)) {
            
            *currentScreen = SCREEN_TYPING;
        }
        if (CheckCollisionPointRec(mouse, menuBtn)) {
            *currentScreen = SCREEN_MODE;
        }
        if (CheckCollisionPointRec(mouse, lbBtn)) {
            *currentScreen = SCREEN_LEADERBOARD;
        }
    }
}

void DrawLeaderboardScreen(GAMESCREEN *currentScreen, Font font1, Font font2) {
    
    // Title
    DrawTextEx(font1, "LEADERBOARD", (Vector2){380, 100}, 80, -2, COLOR1);
    DrawRectangle(380, 190, 680, 2, COLOR1);

    // Headers
    DrawTextEx(font2, "RANK", (Vector2){400, 220}, 35, 2, LIGHT);
    DrawTextEx(font2, "NAME", (Vector2){580, 220}, 35, 2, LIGHT);
    DrawTextEx(font2, "WPM", (Vector2){820, 220}, 35, 2, LIGHT);
    DrawTextEx(font2, "ACCURACY", (Vector2){980, 220}, 35, 2, LIGHT);

    DrawRectangle(380, 260, 680, 2, LIGHT);

    // Placeholder text until Person 4 is ready
    DrawTextEx(font2, "No scores yet!", (Vector2){550, 400}, 40, 2, LIGHT);

    // Back button
    Rectangle backBtn = {620, 750, 200, 70};
    DrawRectangleRounded(backBtn, 0.5f, 64, COLOR2);
    DrawRectangleRoundedLinesEx(backBtn, 0.5f, 64, 2.0f, COLOR1);
    DrawTextEx(font2, "BACK", (Vector2){675, 768}, 35, 2, COLOR1);

    // Check click
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, backBtn)) {
            *currentScreen = SCREEN_MODE;
        }
    }
}