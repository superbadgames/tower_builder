#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Entity.hpp>
#include <Tower/Managers/EntityManager.hpp>
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

        void Update(F32 delta);

        void SetPosition(const glm::vec3& pos);

    private:
        Tower::p_Entity _entity;
        Tower::AxisAngle _rotation;
    };
}