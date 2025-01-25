#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <vector>

namespace Tower
{
    struct SpriteData
    {

        std::vector<F32> vertexPositions
        {
             1.0F,  1.0F, // Top Right
            -1.0f,  1.0f, // Bottom Right
            -1.0f, -1.0f, // Bottom Left
             1.0f, -1.0f  // Top Left
        };


        std::vector<F32> vertexUvs
        {
            1.0f, 1.0f, // Top Right
            1.0f, 0.0f, // Bottom Right
            0.0f, 0.0f, // Bottom Left
            0.0f, 1.0f  // Top Left
        };


        std::vector<U32> indices
        {
            0, 1, 3,     // first triangle
            1, 2, 3     // second triangle
        };
    };
}
