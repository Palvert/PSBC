#include "./raylib/include/raylib.h"
#include "widgets.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//---------------------------------------------------------------------------------
// BUTTON
//---------------------------------------------------------------------------------
void init_button(Button *btn, char *label_text, int posx, int posy, 
                 char *path_up, char *path_hover, char *path_down, char *font_path, 
                 int label_posx, int label_posy, int font_size, int font_space, 
                 Color font_color) {
    btn->texture_norm  = LoadTexture(path_up);
    btn->texture_hover = LoadTexture(path_hover);
    btn->texture_press = LoadTexture(path_down);
    btn->rect  = (Rectangle){posx, posy, btn->texture_norm.width, btn->texture_norm.height};
    btn->label_text = label_text;
    btn->font  = LoadFont(font_path);
    btn->label_position = (Vector2){posx + label_posx, posy + label_posy};
    btn->font_size      = font_size;
    btn->font_space     = font_space;
    btn->font_color     = font_color;
}

void draw_button(Button *btn) {
    // Texture
    if (CheckCollisionPointRec(GetMousePosition(), btn->rect) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        // click
        DrawTexture(btn->texture_norm, btn->rect.x, btn->rect.y, WHITE);
    } else if (CheckCollisionPointRec(GetMousePosition(), btn->rect)) {
        // hover
        DrawTexture(btn->texture_hover, btn->rect.x, btn->rect.y, WHITE);
    } else {
        // normal
        DrawTexture(btn->texture_norm, btn->rect.x, btn->rect.y, WHITE);
    }

    // Label
    DrawTextEx(btn->font, btn->label_text, btn->label_position, btn->font_size, btn->font_space, btn->font_color); \
}

bool is_button_clicked(Button *btn) {
    if (CheckCollisionPointRec(GetMousePosition(), btn->rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return true;
    } else {
        return false;
    }
}
