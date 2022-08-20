
#include <stdio.h>
#include <stdlib.h>

#include "main.hpp"

int main(const int /* argc */, char const *argv[])
{
    // glog setup
    google::InitGoogleLogging(argv[0]); 

    // Create window (and OpenGL context in the background)
    InitWindow(Main::screenWidth, Main::screenHeight, "raylib [core] example - 3d camera mode");

    // Define the camera to look into our 3d world
    Camera3D camera;
    // Vector3 coordinates
    camera.position = { 0.0f, 10.0f, 10.0f };       // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };           // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };               // Camera up vector (rotation towards target)

    camera.fovy = 45.0f;                            // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;         // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Destroy window (and backend OpenGL context)
    CloseWindow(); 

    return EXIT_SUCCESS;
}
