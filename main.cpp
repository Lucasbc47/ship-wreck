// main.cpp
#include "raylib.h"
#include "aa.h"

int main(void) {
    const int screenHeight = 800;
    const int screenWidth = 600;

    InitWindow(screenHeight, screenWidth, "Teste");
    SetTargetFPS(60);

    PlayerObj playerObj(400, 400, 2, 0);
    

    while (!WindowShouldClose()) {
        BeginDrawing();

        playerObj.Movement();
        playerObj.Draw();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


