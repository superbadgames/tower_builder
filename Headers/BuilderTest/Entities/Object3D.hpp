#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Rendering/Renderer.hpp>
#include <Tower/Managers/RenderingManager.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>

namespace BuilderTest
{
    class Object3D
    {
    public:
        Object3D(void);

        ~Object3D(void);

        void Init(const string& modelId, const string& textureId);

        void Update(F32 delta);

        void SetPosition(const glm::vec3& pos);

    private:
        Tower::p_Renderer _renderer;
        Tower::AxisAngle _rotation;
    };
}