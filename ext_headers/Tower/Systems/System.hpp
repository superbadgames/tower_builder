#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <set>

namespace Tower
{
    class System
    {
    public:
        System(void);

        virtual ~System(void);

    protected:
        std::set<EntityID> entities;
    };
    typedef shared_ptr<System> p_System;
}