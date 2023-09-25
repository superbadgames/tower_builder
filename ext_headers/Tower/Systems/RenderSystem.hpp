#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Entity.hpp"
#include "Tower/Rendering/Shader.hpp"
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Tower
{
    class RenderSystem
    {
    public:
        RenderSystem(void);

        ~RenderSystem(void);

        void Init(F32 fov, F32 aspect, F32 nearDraw, F32 farDraw);

        void Draw(p_Entity entity);

    private:
        glm::mat4 _projectionMatrix;
    };
    typedef shared_ptr<RenderSystem> p_RenderSystem;
}