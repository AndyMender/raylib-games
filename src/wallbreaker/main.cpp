
#include <stdio.h>

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
    camera.position = { 4.0f, 2.0f, 4.0f };         // Camera position
    camera.target = { 0.0f, 1.8f, 0.0f };           // Camera looking  forward parallel to plane
    camera.up = { 0.0f, 1.0f, 0.0f };               // Camera up vector (rotation towards target)

    camera.fovy = 45.0f;                            // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;         // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    SetTargetFPS(30);               // Set our game to run at 30 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        UpdateCamera(&camera);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 32.0f, 32.0f }, LIGHTGRAY);       // Draw ground
        DrawCube({ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);           // Draw a green wall
        DrawCube({ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);          // Draw a blue wall
        DrawCube({ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);           // Draw a yellow wall
        DrawCube({ 0.0f, 2.5f, -16.0f }, 32.0f, 5.0f, 1.0f, MAROON );

        EndMode3D();

        DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( 10, 10, 220, 70, BLUE);

        DrawText("First person camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Destroy window (and backend OpenGL context)
    CloseWindow(); 

    return 0;
}
