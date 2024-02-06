// spaceship.hpp
#pragma once

#include "raylib.h"

class Ship
{
public:
    Ship(int x, int y, int speed, float objRotation);
    ~Ship();
    void Draw();
    void Movement();

private:
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void SmoothRotationToZero(float rotationSpeed);

    int x;
    int y;
    int speed;
    float objRotation;
    Texture2D shipTexture;
};
