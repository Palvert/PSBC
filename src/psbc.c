#include "./raylib/include/raylib.h"
#include <stdlib.h>
#include <stdio.h>
// #include <math.h>

#include "widgets.h"

// MAIN WINDOW CONFIG
#define WIN_MAIN_TITLE "Pandora Saga Build Calculator"

// FONT CONFIG
#define FONT_NORM      "./res/fonts/calibri.ttf"
#define FONT_NORM_SIZE 24
#define FONT_NORM_SPC  0

// INNER WINDOWS' SIZE CONFIG
#define WIN_STATS_W 500
#define WIN_STATS_H 500
#define WIN_STATS_OUTL_THIC 2
const Vector2 WIN_STATS_PIVOT = {10, 10};

// IMAGES
// Icons
#define PATH_IMG_STA        "./res/images/STA.png"
#define PATH_IMG_STR        "./res/images/STR.png"
#define PATH_IMG_AGI        "./res/images/AGI.png"
#define PATH_IMG_DEX        "./res/images/DEX.png"
#define PATH_IMG_SPI        "./res/images/SPI.png"
#define PATH_IMG_INT        "./res/images/INT.png"
#define PATH_IMG_LP         "./res/images/LP.png"
#define PATH_IMG_MP         "./res/images/MP.png"
// Buttons
#define PATH_IMG_BTNS_NORM  "./res/images/StatButton_norm.png"
#define PATH_IMG_BTNS_HOVER "./res/images/StatButton_hover.png"
#define PATH_IMG_BTNS_PRESS "./res/images/StatButton_press.png"
#define PATH_IMG_BTN1_NORM  "./res/images/Button_norm_1.png"
#define PATH_IMG_BTN1_HOVER "./res/images/Button_hover_1.png"
#define PATH_IMG_BTN1_PRESS "./res/images/Button_press_1.png"
#define PATH_IMG_BTN2_NORM  "./res/images/Button_norm_2.png"
#define PATH_IMG_BTN2_HOVER "./res/images/Button_hover_2.png"
#define PATH_IMG_BTN2_PRESS "./res/images/Button_press_2.png"

// MACRO
#define DRAW_TEXT_NORM(text, posx, posy) \
    DrawTextEx(FONT_NORMAL, text, (Vector2){posx, posy}, FONT_NORM_SIZE, FONT_NORM_SPC, CLR_WHITE); \

// COLOR PALETTE
const Color CLR_BLACK    = {15, 15, 15, 255};
const Color CLR_WHITE    = {240, 240, 240, 255};
const Color CLR_GRAY     = {130, 130, 130, 255};
const Color CLR_WIN_OUTL = {100, 100, 100, 255};


//------------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, WIN_MAIN_TITLE);

    const Texture2D IMG_LP = LoadTexture(PATH_IMG_LP);

    // Init labels
    Label lbl_static_race;
    init_label(&lbl_static_race, "Race: ", FONT_NORM, 
               (Vector2){WIN_STATS_PIVOT.x + 10, WIN_STATS_PIVOT.y + 10},
               FONT_NORM_SIZE, FONT_NORM_SPC, CLR_GRAY);
    Label lbl_dynamic_race;
    init_label(&lbl_dynamic_race, "Lapin", FONT_NORM, 
               (Vector2){lbl_static_race.position.x + 90, lbl_static_race.position.y},
               FONT_NORM_SIZE, FONT_NORM_SPC, CLR_WHITE);

    // Init buttons
    Button btn_test;
    init_button(&btn_test, "", WIN_STATS_PIVOT.x + 100, WIN_STATS_PIVOT.y + 50, 
                PATH_IMG_BTNS_NORM, PATH_IMG_BTNS_HOVER, PATH_IMG_BTNS_PRESS,
                FONT_NORM, 0, 0, FONT_NORM_SIZE, FONT_NORM_SPC, CLR_WHITE);

    // Button btn_big;
    // init_button(&btn_big, "Test", WIN_STATS_PIVOT.x + 140, WIN_STATS_PIVOT.y + 50, 
    //             PATH_IMG_BTN2_NORM, PATH_IMG_BTN2_HOVER, PATH_IMG_BTN2_PRESS,
    //             FONT_NORM, 19, 4, FONT_NORM_SIZE, FONT_NORM_SPC, CLR_WHITE);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (is_button_clicked(&btn_test)) { rename_label(&lbl_dynamic_race, "Enkidu"); }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(CLR_BLACK);

            // WINDOW LAYOUT "STATS"
            // Window outline
            DrawRectangleLinesEx((Rectangle){WIN_STATS_PIVOT.x, WIN_STATS_PIVOT.y, 
                    WIN_STATS_W, WIN_STATS_H}, WIN_STATS_OUTL_THIC, CLR_WIN_OUTL);
            // Text static
            draw_label(&lbl_static_race);
            // Text dynamic
            draw_label(&lbl_dynamic_race);

            // Icons
            DrawTexture(IMG_LP, WIN_STATS_PIVOT.x + 10, WIN_STATS_PIVOT.y + 30, WHITE);

            draw_button(&btn_test);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
