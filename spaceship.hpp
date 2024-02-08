// spaceship.hpp
#pragma once

#include "raylib.h"
#define PLAYER_MAX_SHOOTS 3

class Ship
{
public:
    Ship(int x, int y, int speed, float objRotation);
    ~Ship();
    void Draw();
    void Movement();
    void Reset();
    Vector2 GetPosition();

private:
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void KeepInside();
    void SmoothRotationToZero(float rotationSpeed);

    int x;
    int y;
    int speed;
    float objRotation;
    Texture2D shipTexture;
};

class Shoot
{
public:
    Vector2 position;
    bool active;
    void update();
};