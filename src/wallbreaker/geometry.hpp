
#pragma once

#include <raylib.h>

namespace Geometry {
    class Vector3D: protected Vector3
    {
    public:
        Vector3D(float x, float y, float z) { base = {x, y, z}; }
        Vector3D(const Vector3& other) { base = { other.x, other.y, other.z }; }
        
        // overloads to support basic vector operations
        Vector3D operator+(const Vector3D& other)
        {
            return Vector3D(
                base.x + other.base.x,
                base.y + other.base.y,
                base.z + other.base.z
            );
        }

        Vector3D operator+(const float factor)
        {
            return Vector3D(
                base.x + factor,
                base.y + factor,
                base.z + factor
            );
        }

        Vector3D operator-(const Vector3D& other)
        {
            return Vector3D(
                base.x - other.base.x,
                base.y - other.base.y,
                base.z - other.base.z
            );
        }

        Vector3D operator-(const float factor)
        {
            return Vector3D(
                base.x - factor,
                base.y - factor,
                base.z - factor
            );
        }

        // Scaling operators
        Vector3D operator*(const float factor)
        {
            return Vector3D(
                base.x * factor,
                base.y * factor,
                base.z * factor
            );
        }

        Vector3D operator/(const float factor)
        {
            return Vector3D(
                base.x / factor,
                base.y / factor,
                base.z / factor
            );
        }

        // Getters
        constexpr Vector3 data() const { return base; }

    private:
        Vector3 base;
    };
}   // namespace Geometry
