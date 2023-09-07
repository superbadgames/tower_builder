#pragma once

#include "pch.h"
#include "framework.hpp"
#include "Soyokaze/Entities/Crate3D.hpp"
#include <Tower/Components/World.hpp>
#include <Tower/Input/InputController.hpp>
#include <Tower/Components/Camera.hpp>
#include <Tower/Entity.hpp>
#include <glm/vec4.hpp>
#include <vector>

namespace Soyokaze
{
    class SpinningCrates : public Tower::World
    {
    public:

        SpinningCrates(void);

        ~SpinningCrates(void);

        void v_Init(Tower::p_Director director) final;

        void v_Update(void) final;

        void v_Render(void) final;

    private:
        Tower::p_InputController _controller;
        std::vector<Crate3D> _crates3D;
        Tower::Entity _crate2D_1;
        Tower::Entity _crate2D_2;
        glm::vec4 _blueColor;
        glm::vec4 _redColor;
        F32 _angle1;
        F32 _angle2;
        F32 _offset;
        F32 _direction;
    };
}