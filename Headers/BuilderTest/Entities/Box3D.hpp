#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Entity.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Managers/ShaderManager.hpp>

namespace BuilderTest
{
    class Box3D
    {
    public:
        Box3D(void);

        ~Box3D(void);

        void Init(void);

        void Draw(const glm::mat4& viewMatrix);

    private:
        Tower::p_Entity _entity;
    };
}