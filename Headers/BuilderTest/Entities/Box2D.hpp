#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Entity.hpp>
#include <Tower/Rendering/Shader.hpp>

namespace BuilderTest
{
    class Box2D
    {
    public:
        Box2D(void);

        ~Box2D(void);

        void Init(Tower::p_Shader, Tower::p_Texture);

        void Draw(const glm::mat4& viewMatrix);
    private:
        Tower::p_Entity _entity;
    };
}