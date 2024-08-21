#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Entity.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Rendering/Color.hpp>
#include <Tower/Input/InputManager.hpp>

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

        void SetPosition(const glm::vec2& pos);

        void SetZPosition(F32 zPos);

        void SetScale(const glm::vec2& scale);

        void SetActive(bool state);

    private:
        Tower::p_Entity _entity;
        bool _active;
        F32 _counter;
        const F32 _timer;
        U32 _currentTexture;
        F32 _moveSpeed;
    };
}