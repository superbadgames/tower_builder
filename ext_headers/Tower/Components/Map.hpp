#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include <glm/mat4x4.hpp>

namespace Tower
{
    class I_Map
    {
    public:
        I_Map(void) {}

        virtual ~I_Map(void) {}

        virtual void v_Init(void) = 0;

        virtual void v_Update(void) = 0;

        virtual void v_Render(void) = 0;

    protected:
    };
    typedef shared_ptr<I_Map> p_Map;
}