#pragma once
#include "pch.h"
#include <Tower/framework.h>

#include "BuilderTest/Entities/Box2D.hpp"


#include <Tower/Components/Map.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Rendering/Color.hpp>

namespace BuilderTest
{
    class TestWorldOne : public Tower::I_Map
    {
    public:
        TestWorldOne();

        ~TestWorldOne();

        void v_Init(void) final;

        inline void v_Release(void) final {}

        void v_Update(F32 delta) final;

        void v_Render(void) final;


    private:
        // Where do we live?
        // Where is out code/behavior defined?
        Box2D _background;
        Box2D _redBox;
        Box2D _greenBox;
        Box2D _blueBox;
        // Why am I here, but not the camera itself?
        F32 _cameraMoveSpeed;

        void _CheckInput(void);
    };
}