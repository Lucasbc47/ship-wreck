// main.cpp
#include "raylib.h"
#include "spaceship.hpp"
#include "asteroids.hpp"

#define HEIGHT 800
#define WIDTH 600
#define TITLE "Ship Wreck"
     

int main(void)
{
    InitWindow(HEIGHT, WIDTH, TITLE);
    SetTargetFPS(60);

    Ship ship(400, 400, 2, 0);
    InitAsteroids();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        UpdateAsteroids();
        DrawAsteroids();

        ship.Movement();
        ship.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
