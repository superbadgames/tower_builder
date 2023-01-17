#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    class MouseInput
    {
    public:
        MouseInput(void);

        ~MouseInput(void);

    private:
        bool _hasMouseMoved;
        GLdouble _mouseXLastPos;
        GLdouble _mouseYLastPos;
        GLdouble _mouseXDelta;
        GLdouble _mouseYDelta;
    };
    typedef shared_ptr<MouseInput> p_MouseInput;
}