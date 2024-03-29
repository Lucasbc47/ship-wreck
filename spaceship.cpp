// spaceship.cpp
#include "spaceship.hpp"
#include <iostream>
#include <algorithm>

Ship::Ship(int x, int y, int speed, float objRotation) : x(x), y(y), speed(speed), objRotation(objRotation)
{
    shipTexture = LoadTexture("img/spaceship.png");
}

Ship::~Ship()
{
    UnloadTexture(shipTexture);
}

void Ship::Draw()
{
    Rectangle sourceRec = {0.0f, 0.0f, static_cast<float>(shipTexture.width), static_cast<float>(shipTexture.height)};
    Rectangle destRec = {static_cast<float>(x), static_cast<float>(y), GetScreenWidth() * 0.07f, GetScreenWidth() * 0.1f};
    DrawTexturePro(shipTexture, sourceRec, destRec, Vector2{GetScreenWidth() * 0.05f, GetScreenWidth() * 0.05f}, objRotation, WHITE);
}

void Ship::Movement()
{
    const float rotationSpeed = 2.5f;

    if (IsKeyDown(KEY_A))
    {
        MoveLeft();
        objRotation = std::max(objRotation - rotationSpeed, -10.0f);
    }
    else if (IsKeyDown(KEY_D))
    {
        MoveRight();
        objRotation = std::min(objRotation + rotationSpeed, 10.0f);
    }
    else
    {
        SmoothRotationToZero(rotationSpeed);
    }

    if (IsKeyDown(KEY_W))
    {
        MoveUp();
    }
    if (IsKeyDown(KEY_S))
    {
        MoveDown();
    }

    KeepInside();
}

Vector2 Ship::GetPosition()
{
    return {static_cast<float>(x), static_cast<float>(y)};
}

void Ship::MoveLeft()
{
    x -= speed;
}

void Ship::MoveRight()
{
    x += speed;
}

void Ship::MoveUp()
{
    y -= speed;
}

void Ship::MoveDown()
{
    y += speed;
}

void Ship::KeepInside()
{
    x = std::clamp(x, 0, 800 - static_cast<int>(GetScreenWidth() * 0.07f));
    y = std::clamp(y, 0, 600 - static_cast<int>(GetScreenWidth() * 0.1f));
}

void Ship::SmoothRotationToZero(float rotationSpeed)
{
    if (objRotation > 0.0f)
    {
        objRotation = std::max(objRotation - rotationSpeed, 0.0f);
    }
    else if (objRotation < 0.0f)
    {
        objRotation = std::min(objRotation + rotationSpeed, 0.0f);
    }
}

void Ship::Reset()
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    objRotation = 0.0f;
}

Texture2D Ship::GetTexture()
{
    return shipTexture;
}

void Shoot::update()
{
    if (active)
    {
        position.y -= 10;
        if (position.y < 0)
        {
            active = false;
        }
    }
}