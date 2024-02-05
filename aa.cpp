// aa.cpp
#include "aa.h"

PlayerObj::PlayerObj(int x, int y, int speed) : x(x), y(y), speed(speed)
{
    playerTexture = LoadTexture("img/spaceship.png");
}

PlayerObj::~PlayerObj()
{
    UnloadTexture(playerTexture);
}

void PlayerObj::Draw()
{
    // dá um resize pra 64x64
    Rectangle sourceRec = {0.0f, 0.0f, (float)playerTexture.width, (float)playerTexture.height};
    Rectangle destRec = {(float)x, (float)y, 64, 64};

    DrawTexturePro(playerTexture, sourceRec, destRec, Vector2{0, 0}, 0, WHITE);
}

void PlayerObj::Movement()
{
    if (IsKeyDown(KEY_A))
    {
        x = x - speed;
    }

    if (IsKeyDown(KEY_D))
    {
        x = x + speed;
    }
    if (IsKeyDown(KEY_W))
    {
        y = y - speed;
    }
    if (IsKeyDown(KEY_S))
    {
        y = y + speed;
    }
}
