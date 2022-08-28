
#pragma once

#include <raylib.h>
#include <raymath.h>

namespace Main { 
    // constants
    // TODO: Drop 'constexpr' and make adjustable from Menu?
    constexpr int SCREEN_WIDTH = 800;       // X
    constexpr int SCREEN_HEIGHT = 450;      // Y

    constexpr float FIELD_WIDTH = 10.0f;    // X
    constexpr float FIELD_HEIGHT = 5.0f;    // Y
    constexpr float FIELD_DEPTH = 15.0f;    // Z

    // X, Y, Z
    constexpr Vector3 ORIGIN_POS = { 0.0f, 0.0f, 0.0f };        // Use as reference point to position other objects
    
    // Standard vectors
    constexpr Vector3 VIEW_TARGET = { 0.0f, 0.0f, -25.0f };     // Initial view target for cameras
    constexpr Vector3 VIEW_ROTATION = { 0.0f, 1.0f, 0.0f };     // Rotation vectors used for calculating angular movement (.f.e of the cameras)

    // Enum of in-game object types to determine behavior, f.e. on collision
    enum class ObjectType
    {
        INVALID_OBJECT_TYPE = 0,
        OBJECT_WALL,                // includes floors
        OBJECT_BLOCK,               // scoring blocks
        OBJECT_DEAD,                // "enemy" blocks/walls which penalize the player
        NUM_OBJECT_TYPES
    };

    // In-game objects with bounding box
    typedef struct GameObject {
        ObjectType type;
        BoundingBox bounding_box;
    } GameObject;

}   // namespace Main
