// aa.cpp
#include "aa.h"
#include <iostream>
#include <algorithm>

PlayerObj::PlayerObj(int x, int y, int speed, float objRotation) : x(x), y(y), speed(speed), objRotation(objRotation)
{
    playerTexture = LoadTexture("img/spaceship.png");
}

PlayerObj::~PlayerObj()
{
    UnloadTexture(playerTexture);
}

void PlayerObj::Draw()
{
    // Create source and destination rectangles
    Rectangle sourceRec = { 0.0f, 0.0f, static_cast<float>(playerTexture.width), static_cast<float>(playerTexture.height) };
    Rectangle destRec = { static_cast<float>(x), static_cast<float>(y), GetScreenWidth()*0.1f, GetScreenWidth()*0.1f };

    // Draw the resized texture
    DrawTexturePro(playerTexture, sourceRec, destRec, Vector2{ GetScreenWidth()*0.05f, GetScreenWidth()*0.05f }, objRotation, WHITE);
}


void PlayerObj::Movement()
{
    const float rotationSpeed = 2.5f;
    if (IsKeyDown(KEY_A))
    {
        x = x - speed;
        objRotation = std::max(objRotation - rotationSpeed, -15.0f);
    } else if (IsKeyDown(KEY_D))
    {
        x = x + speed;
        objRotation = std::min(objRotation + rotationSpeed, 15.0f);
    } else {
        // Se nenhuma tecla de rotação está pressionada, suavize a rotação de volta para 0
        if (objRotation > 0.0f)
            objRotation = std::max(objRotation - rotationSpeed, 0.0f);
        else if (objRotation < 0.0f)
            objRotation = std::min(objRotation + rotationSpeed, 0.0f);
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
