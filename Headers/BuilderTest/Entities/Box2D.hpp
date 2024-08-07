#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Entity.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Rendering/Color.hpp>

namespace BuilderTest
{
    class Box2D
    {
    public:
        Box2D(void);

        ~Box2D(void);

        void Init(Tower::p_Shader, Tower::p_Texture);

        void Draw(const glm::mat4& viewMatrix);

        void Update(F32 delta);

        void SetColor(const Tower::Color& color);

    private:
        Tower::p_Entity _entity;
        F32 _counter;
        const F32 _timer;
        U32 _currentTexture;
    };
}