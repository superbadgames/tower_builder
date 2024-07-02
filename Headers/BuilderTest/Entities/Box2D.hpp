#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Entity.hpp>

namespace BuilderTest
{
    class Box2D
    {
    public:
        Box2D(void);

        ~Box2D(void);
    private:
        Tower::p_Entity _entity;
    };
}