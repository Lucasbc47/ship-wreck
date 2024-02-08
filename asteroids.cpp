// asteroids.cpp
#include "asteroids.hpp"

Asteroid asteroids[MAX_ASTEROIDS];
void InitAsteroids()
{
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        asteroids[i].position.x = GetRandomValue(0, GetScreenWidth());
        asteroids[i].position.y = GetRandomValue(0, GetScreenHeight());
        asteroids[i].speed.x = GetRandomValue(-2, 2);
        asteroids[i].speed.y = GetRandomValue(-2, 2);
        asteroids[i].texture = LoadTexture("./img/asteroid.png");
        asteroids[i].hasCollided = false;
        float asteroidSize = GetScreenWidth() * 0.10f;
        asteroids[i].texture.width = static_cast<int>(asteroidSize);
        asteroids[i].texture.height = static_cast<int>(asteroidSize);
    }
}

void UpdateAsteroids()
{
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        asteroids[i].position.x += asteroids[i].speed.x;
        asteroids[i].position.y += asteroids[i].speed.y;

        if (asteroids[i].position.x > GetScreenWidth() + ASTEROID_RADIUS)
        {
            asteroids[i].position.x = -ASTEROID_RADIUS;
        }
        else if (asteroids[i].position.x < -ASTEROID_RADIUS)
        {
            asteroids[i].position.x = GetScreenWidth() + ASTEROID_RADIUS;
        }
        if (asteroids[i].position.y > GetScreenHeight() + ASTEROID_RADIUS)
        {
            asteroids[i].position.y = -ASTEROID_RADIUS;
        }
        else if (asteroids[i].position.y < -ASTEROID_RADIUS)
        {
            asteroids[i].position.y = GetScreenHeight() + ASTEROID_RADIUS;
        }
    }
}

void DrawAsteroids()
{
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        DrawTextureV(asteroids[i].texture, asteroids[i].position, WHITE);
    }
}

void ResetAsteroids()
{
    for (int i = 0; i < MAX_ASTEROIDS; i++)
    {
        asteroids[i].position = {0, 0};
        asteroids[i].speed = {0, 0};
    }

    InitAsteroids();
}
