#pragma once

#include "pch.h"
#include "Tower/framework.h"


namespace Tower
{
    class Text
    {
    public:
        Text(void);

        ~Text(void);
    private:
        GLuint _vao;    // Vertex Array Object
        GLuint _vbo;    // Vertex Buffer Object

    };
}