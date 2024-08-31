#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Components/World.hpp>
#include <Tower/UI/Glyph.hpp>
#include <Tower/UI/Font.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Rendering/Color.hpp>
#include "BuilderTest/Entities/Box2D.hpp"

namespace BuilderTest
{
    class TestWorldOne : public Tower::World
    {
    public:
        TestWorldOne();

        ~TestWorldOne();

        void v_Init(void) final;

        void v_Update(void) final;

        void v_Render(void) final;

    private:
        Box2D _background;
        Box2D _redBox;
        Box2D _greenBox;
        Box2D _blueBox;
        Tower::Glyph _glyph_S;
        Tower::p_Font _font;
        Tower::Color _glyphColor;
        F32 _cameraMoveSpeed;

        void _CheckInput(void);
    };
}