#include "./raylib/include/raylib.h"
#include "widgets.h"
#include <stdbool.h>


void draw_button(Button btn) {
    
}

bool is_button_clicked(Button *btn) {
    if (CheckCollisionPointRec(GetMousePosition(), btn->rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return true;
    } else {
        return false;
    }
}
