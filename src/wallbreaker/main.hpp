
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
    constexpr Vector3 ORIGIN_POS = { 0.0f, 0.0f, 0.0f };     // Use as reference point to position other objects

 }   // namespace Main
