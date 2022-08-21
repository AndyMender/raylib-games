
#include <stdio.h>

#include <glog/logging.h>
#include <raylib.h>
#include <raymath.h>

#include "main.hpp"

int main(const int /* argc */, char const *argv[])
{
    // glog setup
    google::InitGoogleLogging(argv[0]); 

    // Create window (and OpenGL context in the background)
    InitWindow(Main::screenWidth, Main::screenHeight, "Wallbreaker - a 3D Breakout clone!");

    Vector3 originPos = { 0.0f, 0.0f, 0.0f };       // Use as reference point to position other objects

    // Define basic 3D camera
    Camera3D camera;
    camera.position = Vector3Add(originPos, {0.0f, 2.0f, 0.0f});
    camera.target = { 0.0f, 0.0f, -25.0f };             // Camera looking - forward parallel to plane
    camera.up = { 0.0f, 1.0f, 0.0f };                   // Camera up vector (rotation towards target)

    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    // Set cam for FPP movement
    SetCameraMode(camera, CAMERA_FIRST_PERSON);

    // Set FPS (30 or 60)
    SetTargetFPS(30);
    //--------------------------------------------------------------------------------------

    // Main game loop
    // NOTE: Detect window close button or ESC key
    while (!WindowShouldClose())
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

        // Draw ground and ceiling
        DrawPlane(originPos, { 12.0f, 20.0f }, LIGHTGRAY);

        // Add coord center guides
        DrawCubeWires(originPos, 0.5f, 0.5f, 0.5f, BLUE);
        DrawCubeWires(originPos, 0.75f, 0.75f, 0.75f, BLUE);

        // TODO: Remove X, Y, Z guides later
        // X-axis
        DrawCubeWires(
            Vector3Add(originPos, { 1.0f, 0.0f, 0.0f }),
            0.5f, 0.5f, 0.5f,
            RED
        );
        // Y-axis
        DrawCubeWires(
             Vector3Add(originPos, { 0.0f, 1.0f, 0.0f }),
            0.5f, 0.5f, 0.5f,
            LIME
        );
        // Z-axis
        DrawCubeWires(
            Vector3Add(originPos, { 0.0f, 0.0f, 1.0f }),
            0.5f, 0.5f, 0.5f,
            SKYBLUE
        );

        // Draw walls
        DrawCube({ 6.5f, 2.5f, 0.0f }, 1.0f, 5.0f, 20.0f, LIME);
        DrawCube({ -6.5f, 2.5f, 0.0f }, 1.0f, 5.0f, 20.0f, BLUE);
        DrawCube({ 0.0f, 2.5f, 10.5f }, 12.0f, 5.0f, 1.0f, GOLD);
        DrawCube({ 0.0f, 2.5f, -10.5f }, 12.0f, 5.0f, 1.0f, MAROON );

        EndMode3D();

        // Stats board
        DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( 10, 10, 220, 70, BLUE);

        // Stats board content
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
