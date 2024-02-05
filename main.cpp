// main.cpp
#include "raylib.h"
#include "aa.h"

int main(void) {
    const int screenHeight = 800;
    const int screenWidth = 450;

    InitWindow(screenHeight, screenWidth, "Teste");
    SetTargetFPS(60);

    PlayerObj playerObj(400, 400, 2);
    

    while (!WindowShouldClose()) {
        BeginDrawing();

        playerObj.Movement();
        playerObj.Draw();

        ClearBackground(RAYWHITE);
        DrawText("Eh o Babaz", 400, 225, 20, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
