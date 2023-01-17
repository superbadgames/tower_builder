#pragma once

#include "pch.h"
#include "Tower/framework.h"

#include <vector>

namespace Tower
{
    struct CubeData
    {
        // Origin is on the bottom face, in the center.
        std::vector<F32> vertices{
            -0.5f, 0.0f, 0.5f,      // front bottom left
            0.5f, 0.0f, 0.5f,       // front bottom right
            -0.5f, 1.0f, 0.5f,      // front top left
            0.5f, 1.0f, 0.5f,       // front top right

            -0.5f, 0.0f, -0.5f,     // back bottom left
            0.5f, 0.0f, -0.5f,      // back bottom right
            -0.5f, 1.0f, -0.5f,     // back top left
            0.5f, 1.0f, -0.5f      // back top right
        };


        std::vector<U32> indices{
            0, 1, 2,        // front face
            1, 2, 3,
            1, 5, 3,        // right face
            5, 3, 7,
            4, 5, 6,        // back face
            5, 6, 7,
            2, 3, 6,        // top face
            3, 6, 7,
            4, 0, 6,        // left face
            0, 6, 2,
            4, 5, 0,        // bottom face
            4, 5, 1
        };


        std::vector<F32> uvs{
            0.0f, 0.0f,     // bottom left
            1.0f, 0.0f,     // bottom right
            0.0f, 1.0f,     // top left
            1.0f, 1.0f,     // top right

            0.0f, 0.0f,     // bottom left
            1.0f, 0.0f,     // bottom right
            0.0f, 1.0f,     // top left
            1.0f, 1.0f,     // top right
        };

        std::array<F32, 12> normals{

        };

    };
}
