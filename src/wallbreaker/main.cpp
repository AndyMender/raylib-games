
#include <stdio.h>
#include <vector>

#include <glog/logging.h>

#include "main.hpp"

int main(const int /* argc */, char const *argv[])
{
    std::vector<Main::GameObject> game_objects;   

    // glog setup
    google::InitGoogleLogging(argv[0]); 

    // Create window (and OpenGL context in the background)
    InitWindow(Main::SCREEN_WIDTH, Main::SCREEN_HEIGHT, "Wallbreaker - a 3D Breakout clone!");

    // Define basic 3D camera
    Camera3D playerCam;
    playerCam.position = Vector3Add(Main::ORIGIN_POS, { 0.0f, 2.0f, -6.0f });
    playerCam.target = Main::VIEW_TARGET;                                       // Camera looking - forward parallel to plane
    playerCam.up = Main::VIEW_ROTATION;                                         // Camera up vector (rotation towards target)

    playerCam.fovy = 45.0f;                                                     // Camera field-of-view Y
    playerCam.projection = CAMERA_PERSPECTIVE;                                  // Camera mode type

    // Use a moving cam for ray-casting collision
    // NOTE: We don't need to register the ball as a game object, because it's the player object
    Camera3D ballCam;
    ballCam.position = Vector3Add(Main::ORIGIN_POS, { 0.0f, 2.0f, 0.0f });
    ballCam.target = Main::VIEW_TARGET;
    ballCam.up = Main::VIEW_ROTATION; 
    ballCam.fovy = 45.0f;
    ballCam.projection = CAMERA_PERSPECTIVE;

    // Set cam for FPP movement
    SetCameraMode(playerCam, CAMERA_FIRST_PERSON);

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
        UpdateCamera(&playerCam);

        // GetRayCollisionBox();
        // GetRayColi

        // TODO: Add ray-casting collision
        // https://github.com/raysan5/raylib/blob/master/examples/shapes/shapes_collision_area.c
        // https://github.com/raysan5/raylib/blob/master/examples/text/text_draw_3d.c
        // https://github.com/raysan5/raylib/blob/5840cd6e50890fdc8bb964cf4ed86524f1ca1675/examples/models/models_mesh_picking.c
        // https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection
        // https://gamedev.stackexchange.com/questions/34602/raycasting-collision-detection
        // https://hal.inria.fr/file/index/docid/319404/filename/grapp08.pdf

        ballCam.position = Vector3Add(
            ballCam.position,
            {
                static_cast<float>(GetRandomValue(-1, 1)) / GetRandomValue(20, 200),
                static_cast<float>(GetRandomValue(-1, 1)) / GetRandomValue(20, 200),
                static_cast<float>(GetRandomValue(-1, 1)) / GetRandomValue(20, 200),
            }
        );

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(playerCam);

        // Add coord center guides
        DrawCubeWires(Main::ORIGIN_POS, 0.25f, 0.25f, 0.25f, BLUE);

        // Draw ground and ceiling
        DrawCube(Main::ORIGIN_POS, Main::FIELD_WIDTH, 0.01f, Main::FIELD_DEPTH, LIGHTGRAY);
        DrawCube(
            Vector3Add(Main::ORIGIN_POS, { 0.0f, Main::FIELD_HEIGHT, 0.0f }),
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

        // Draw items
        DrawSphere(ballCam.position, 0.2f, GOLD);
        // DrawSphereWires(ballPos, 0.2f, 8, 8, DARKGRAY);

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
