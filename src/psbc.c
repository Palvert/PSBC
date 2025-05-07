#include "raylib/include/raylib.h"
#include <stdlib.h>
#include <stdio.h>
// #include <math.h>

// FONT SETTINGS
#define FONT_NORM      "./res/fonts/calibri.ttf"
#define FONT_NORM_SIZE 16
#define FONT_NORM_SPC  5

// IMAGES
#define IMG_STA        "./res/icons/STA.png"
#define IMG_STR        "./res/icons/STR.png"
#define IMG_AGI        "./res/icons/AGI.png"
#define IMG_DEX        "./res/icons/DEX.png"
#define IMG_SPI        "./res/icons/SPI.png"
#define IMG_INT        "./res/icons/INT.png"
#define IMG_LP         "./res/icons/LP.png"
#define IMG_MP         "./res/icons/MP.png"

// COLOR PALETTE
const Color CLR_BLACK = {15, 15, 15, 255};
const Color CLR_WHITE = {220, 220, 220, 255};



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pandora Saga Build Calculator");
    const Font font_normal = LoadFont(FONT_NORM);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(CLR_BLACK);

            DrawTextEx(font_normal, "Hello Kekworld", (Vector2){10, 10}, FONT_NORM_SIZE, FONT_NORM_SPC, CLR_WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
