#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Input/InputButtons.hpp"
#include "Tower/Input/InputBindings.hpp"
#include <map>

namespace Tower
{
    class KeyboardInput
    {
    public:
        KeyboardInput(void);

        ~KeyboardInput(void);

        void AddAction(string action, InputButton button, InputButtonState activeState);

        void KeyPress(ButtonPress update);

        bool IsActionActivated(string name);

    private:
        InputBindings _actions;

    };
    typedef std::shared_ptr<KeyboardInput> p_KeyboardInput;
}