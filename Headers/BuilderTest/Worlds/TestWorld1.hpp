#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Components/World.hpp>
#include "BuilderTest/Entities/Box2D.hpp"

namespace BuilderTest
{
    class TestWorldOne : public Tower::World
    {
    public:
        TestWorldOne();

        ~TestWorldOne();

        void v_Init(Tower::p_Director director) final;

        void v_Update(void) final;

        void v_Render(const glm::mat4& viewMatrix) final;
    private:
        Box2D _blueBox;
    };
}