#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <vector>

namespace Tower
{
    struct CubeData
    {
        // Because an indexed draw is going to be done, each vertex only need be defined once
        std::vector<F32> vertexPositions
        {
            -1.0f, 1.0f, 1.0f, // Left, Top, Front
            1.0f, 1.0f, 1.0f,  // Right, Top, Front
            1.0f, -1.0f, 1.0f, // Right, Bottom, Front
            -1.0f, -1.0f, 1.0f, // Left, Bottom, Front
            1.0f, 1.0f, -1.0f, // Right, Top, Back
            -1.0f, 1.0f, -1.0f, // Left, Top, Back
            -1.0f, -1.0f, -1.0f, // Left, Bottom, Back
            1.0f, -1.0f, -1.0f // Right, Bottom, Back
        };

        // Each vertex will need an individual UV
        std::vector<F32> vertexUvs
        {
            // Front Face
            
        };

        std::vector<U32> indices
        {
            // Front Face
            // Top Left -> Top Right -> Bottom Right
            0, 1, 2,
            // Top Left -> Bottom Right -> Bottom Left
            0, 2, 3
        };
    };
}