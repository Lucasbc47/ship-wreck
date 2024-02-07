// asteroids.hpp
#pragma once

#include "raylib.h"

#define MAX_ASTEROIDS 9
#define ASTEROID_RADIUS 10

struct Asteroid
{
    Vector2 position;
    Vector2 speed;
    Color color;
};

extern Asteroid asteroids[MAX_ASTEROIDS];

void InitAsteroids();
void UpdateAsteroids();
void DrawAsteroids();
void ResetAsteroids();
