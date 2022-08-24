
#include <stdio.h>

#include <glog/logging.h>

#include "main.hpp"

int main(const int /* argc */, char const *argv[])
{
    // glog setup
    google::InitGoogleLogging(argv[0]); 

    // Create window (and OpenGL context in the background)
    InitWindow(Main::SCREEN_WIDTH, Main::SCREEN_HEIGHT, "Wallbreaker - a 3D Breakout clone!");

    // Define basic 3D camera
    Camera3D camera;
    camera.position = Vector3Add(Main::ORIGIN_POS, {0.0f, 2.0f, -6.0f});
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

        // Add coord center guides
        DrawCubeWires(Main::ORIGIN_POS, 0.5f, 0.5f, 0.5f, BLUE);

        // TODO: Remove X, Y, Z guides later
        // X-axis
        DrawCubeWires(
            Vector3Add(Main::ORIGIN_POS, { 1.0f, 0.0f, 0.0f }),
            0.5f, 0.5f, 0.5f,
            RED
        );
        // Y-axis
        DrawCubeWires(
             Vector3Add(Main::ORIGIN_POS, { 0.0f, 1.0f, 0.0f }),
            0.5f, 0.5f, 0.5f,
            LIME
        );
        // Z-axis
        DrawCubeWires(
            Vector3Add(Main::ORIGIN_POS, { 0.0f, 0.0f, 1.0f }),
            0.5f, 0.5f, 0.5f,
            SKYBLUE
        );

        // Draw ground and ceiling
        DrawCube(Main::ORIGIN_POS, Main::FIELD_WIDTH, 0.01f, Main::FIELD_DEPTH, LIGHTGRAY);
        DrawCube(
            Vector3Add(Main::ORIGIN_POS, {0.0f, Main::FIELD_HEIGHT, 0.0f}),
            Main::FIELD_WIDTH, 0.01f, Main::FIELD_DEPTH,
            LIGHTGRAY
        );

        // Draw walls
        DrawCube(
            Vector3Add(Main::ORIGIN_POS, { Main::FIELD_WIDTH/2, Main::FIELD_HEIGHT/2, 0.0f }),
            0.01f, Main::FIELD_HEIGHT, Main::FIELD_DEPTH,
            SKYBLUE
        );
        DrawCube(
            Vector3Add(Main::ORIGIN_POS, { -Main::FIELD_WIDTH/2, Main::FIELD_HEIGHT/2, 0.0f }),
            0.01f, Main::FIELD_HEIGHT, Main::FIELD_DEPTH,
            SKYBLUE
        );
 
        DrawCube(
            Vector3Add(Main::ORIGIN_POS, { 0.0f, Main::FIELD_HEIGHT/2, Main::FIELD_DEPTH/2 }),
            Main::FIELD_WIDTH, Main::FIELD_HEIGHT, 0.01f,
            DARKBLUE
        );
        DrawCube(
            Vector3Add(Main::ORIGIN_POS, { 0.0f, Main::FIELD_HEIGHT/2, -Main::FIELD_DEPTH/2 }),
            Main::FIELD_WIDTH, Main::FIELD_HEIGHT, 0.01f,
            DARKGRAY
        );

        EndMode3D();

        // Stats board
        DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 220, 70, BLUE);

        // Stats board content
        DrawText("First person camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);
        DrawFPS(Main::SCREEN_WIDTH - 80, Main::SCREEN_HEIGHT - 20);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Destroy window (and backend OpenGL context)
    CloseWindow(); 

    return 0;
}
