#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    class World
    {
    public:
        World(void) {}

        virtual ~World(void) {}

        virtual void v_Init(void) = 0;

        virtual void v_Update(void) = 0;

        virtual void v_Render(void) = 0;
    };
}