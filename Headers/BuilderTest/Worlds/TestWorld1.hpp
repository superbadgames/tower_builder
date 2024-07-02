#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Components/World.hpp>

namespace BuilderTest
{
    class TestWorldOne : public Tower::World
    {
    public:
        TestWorldOne();

        ~TestWorldOne();

        void v_Init(Tower::p_Director director) final;

        void v_Update(void) final;

        void v_Render(void) final;
    private:
    };
}