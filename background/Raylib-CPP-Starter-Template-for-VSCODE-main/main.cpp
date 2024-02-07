#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    // Initialization
    InitWindow(screenWidth, screenHeight, "Background Example");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    // Load background images
    Texture2D background1 = LoadTexture("Background.png");
    Texture2D background2 = LoadTexture("Background.png");
    

    float backgroundPosY1 = 0;
    float backgroundPosY2 = -screenHeight;
    float backgroundSpeed = 3.0f;
  

    // Main game loop
    while (!WindowShouldClose()) {
        // Update logic here
        backgroundPosY1 += backgroundSpeed;
        backgroundPosY2 += backgroundSpeed;

        // If the backgrounds have completely passed the screen, reset their positions
        if (backgroundPosY1 >= screenHeight)
            backgroundPosY1 = -screenHeight;
        if (backgroundPosY2 >= screenHeight)
            backgroundPosY2 = -screenHeight;

        // Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);  // Clear the screen

        // Draw the backgrounds
        DrawTextureEx(background1, {0, backgroundPosY1}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(background2, {0, backgroundPosY2}, 0.0f, 1.0f, WHITE);

        EndDrawing();
    }

    // Unload textures
    UnloadTexture(background1);
    UnloadTexture(background2);

    // Close window
    CloseWindow();

    return 0;
}
