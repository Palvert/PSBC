#pragma once

#include "./raylib/include/raylib.h"
#include <stdbool.h>


typedef struct Button {
    Texture2D texture_norm;
    Texture2D texture_hover;
    Texture2D texture_press;
    Rectangle rect;
} Button;


void draw_button(Button btn);
bool is_button_clicked(Button *btn);
