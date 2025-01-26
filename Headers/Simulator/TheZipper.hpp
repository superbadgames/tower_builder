#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Entity.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>

namespace Simulator
{
    class TheZipper
    {
    public:
        TheZipper(void);

        ~TheZipper(void);

        void Init(const glm::vec3& position);

        void Draw(const glm::mat4& viewMatrix);

        void Update(F32 delta);

        void SetPosition(const glm::vec3& pos);

    private:
        Tower::p_Entity _entity;
        Tower::AxisAngle _rotation;
    };
}