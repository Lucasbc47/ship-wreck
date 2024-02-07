// main.cpp
#include "raylib.h"
#include "spaceship.hpp"
#include "asteroids.hpp"
#include "hpdraw.hpp"

#include <iostream>

#define HEIGHT 800
#define WIDTH 600
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

    InitWindow(HEIGHT, WIDTH, TITLE);
    InitAudioDevice();
    SetTargetFPS(60);

    // Musica
    /* Music music = LoadMusicStream("output/tema.ogg");
    PlayMusicStream(music); */

    Hp hp(3);
    Ship ship(400, 400, 2, 0);
    InitAsteroids();

    while (!WindowShouldClose())
    {
        /*  UpdateMusicStream(music);/ */
        BeginDrawing();
        ClearBackground(RAYWHITE);

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

    CloseWindow();
}
