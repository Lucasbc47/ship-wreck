// main.cpp
#include "raylib.h"
#include "spaceship.hpp"
#include "asteroids.hpp"
#include "hpdraw.hpp"

#include <iostream>

#define HEIGHT 600
#define WIDTH 800
#define TITLE "Ship Wreck"

void startGame();

int main(void)
{
    startGame();
    return 0;
}

void startGame()
{
    bool gameOver = false;
    bool gameStarted = false;

    InitWindow(WIDTH, HEIGHT, TITLE);
    InitAudioDevice();
    SetTargetFPS(60);

    Image backgroundImage = LoadImage("img/background.png");
    ImageResize(&backgroundImage, WIDTH, HEIGHT);
    Texture2D background = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    float backgroundPosY = 0;
    float backgroundSpeed = 3.0f;

    Hp hp(20);
    Ship ship(400, 400, 2, 0);
    InitAsteroids();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        backgroundPosY += backgroundSpeed;

        if (backgroundPosY >= HEIGHT)
            backgroundPosY = 0;

        DrawTextureEx(background, {0, backgroundPosY}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(background, {0, backgroundPosY - HEIGHT}, 0.0f, 1.0f, WHITE);

        if (gameStarted && !gameOver)
        {
            UpdateAsteroids();
            DrawAsteroids();

            hp.Draw();
            ship.Movement();
            ship.Draw();

            for (int i = 0; i < MAX_ASTEROIDS; i++)
            {
                Rectangle asteroidRect = {asteroids[i].position.x - ASTEROID_RADIUS, asteroids[i].position.y - ASTEROID_RADIUS, 2 * ASTEROID_RADIUS, 2 * ASTEROID_RADIUS};

                if (CheckCollisionCircleRec(ship.GetPosition(), 5.0f, asteroidRect))
                {
                    gameOver = true;
                }
            }
        }

        if (gameOver)
        {
            DrawText("GAME OVER!", GetScreenWidth() / 2 - MeasureText("GAME OVER!", 20) / 2, GetScreenHeight() / 2 - 50, 20, RED);

            if (IsKeyPressed(KEY_ENTER))
            {
                gameOver = false;
                gameStarted = false;
                ship.Reset();
                ResetAsteroids();
            }
        }
        else if (!gameStarted)
        {
            DrawText("PRESS [ENTER] TO PLAY", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

            if (IsKeyPressed(KEY_ENTER))
            {
                gameStarted = true;
            }
        }

        EndDrawing();
    }

    UnloadTexture(background);
    // CloseAudioDevice();
    CloseWindow();
}