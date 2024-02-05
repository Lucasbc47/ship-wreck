// aa.cpp
#include "aa.h"

PlayerObj::PlayerObj(int x, int y, int speed) : x(x), y(y), speed(speed) {
    playerTexture = LoadTexture("img/spaceship.png");
}

PlayerObj::~PlayerObj() {
    UnloadTexture(playerTexture);
}

void PlayerObj::Draw() {
    DrawTexture(playerTexture, x, y, WHITE);
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
