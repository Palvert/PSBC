#pragma once

#include "./raylib/include/raylib.h"
#include <stdbool.h>


//---------------------------------------------------------------------------------
// BUTTON
//---------------------------------------------------------------------------------
typedef struct Button {
    Texture2D texture_norm;
    Texture2D texture_hover;
    Texture2D texture_press;
    Rectangle rect;
    Font      font;
    char     *label_text;
    Vector2   label_position;
    int       font_size;
    int       font_space;
    Color     font_color;
} Button;


void init_button(Button *btn, char *label_text, int posx, int posy, 
                 char *path_up, char *path_hover, char *path_down, char *font_path, 
                 int label_posx, int label_posy, int font_size, int font_space, 
                 Color font_color);
void draw_button(Button *btn);
bool is_button_clicked(Button *btn);
