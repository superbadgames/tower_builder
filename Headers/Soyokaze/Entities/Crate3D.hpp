#pragma once

#include "pch.h"
#include "framework.hpp"
#include <Tower/Entity.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <glm/vec3.hpp>

namespace Soyokaze
{
    class Crate3D
    {
    public:
        Crate3D(void);

        Crate3D(Tower::p_Shader shader);

        Crate3D(const string& modelFilepath, const string& texture, Tower::p_Shader shader);

        ~Crate3D(void);

        void Init(const string& modelFilepath, const string& texture, Tower::p_Shader shader);

        void Init(Tower::p_Shader shader);

        //   void Draw(Tower::p_Camera camera);

        void Update(F32 delta, F32 modifier);

        void SetPosition(const glm::vec3& position);

        void SetScale(const glm::vec3& scale);

    private:
        Tower::Entity _entity;
        F32 _rotationSpeed;
        F32 _angle;
        glm::vec3 _axis;
    };
}