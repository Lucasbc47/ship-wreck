// aa.cpp
#include "aa.h"

PlayerObj::PlayerObj(int x, int y, int speed) : x(x), y(y), speed(speed) {}
PlayerObj::ImgRender(){
    Image image;
    texture = LoadTextureFromImage(image);
}

void PlayerObj::Draw() {
    DrawRectangle(x, y, 50, 50, DARKBLUE);
}

void PlayerObj::Movement() {
    if (IsKeyDown(KEY_A)) {
        x = x - speed;
    }

    if (IsKeyDown(KEY_D)) {
        x = x + speed;
    }
    if (IsKeyDown(KEY_W)) {
        y = y - speed;
    }
    if (IsKeyDown(KEY_S)) {
        y = y + speed;
    }
}
