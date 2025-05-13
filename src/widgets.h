#pragma once

#include "./raylib/include/raylib.h"
#include <stdbool.h>


//---------------------------------------------------------------------------------
// BUTTON
//---------------------------------------------------------------------------------
typedef struct Button {
    Texture2D      texture_norm;
    Texture2D      texture_hover;
    Texture2D      texture_press;
    Rectangle      rect;
    Font           font;
    char          *label_text;
    Vector2        label_position;
    unsigned short font_size;
    unsigned short font_space;
    Color          font_color;
} Button;


void init_button(Button *btn, char *label_text, int posx, int posy, 
                 char *path_up, char *path_hover, char *path_down, char *font_path, 
                 int label_posx, int label_posy, unsigned short font_size, 
                 unsigned short font_space, Color font_color);

void draw_button(Button *btn);

bool is_button_clicked(Button *btn);

//---------------------------------------------------------------------------------
// LABEL
//---------------------------------------------------------------------------------
typedef struct Label {
    char* text;
    Font font;
    Vector2 position;
    unsigned short font_size;
    unsigned short font_space;
    Color font_color;
} Label;

void init_label(Label *lbl, char* text, char *font, Vector2 position, 
                unsigned short font_size, unsigned short font_space, Color font_color);

void draw_label(Label *lbl);

void rename_label(Label *lbl, char *text);
