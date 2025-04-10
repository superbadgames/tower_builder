#pragma once
#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Components/World.hpp>
#include "BuilderTest/Entities/Box2D.hpp"

#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Rendering/Color.hpp>
#include <Tower/Cameras/Camera2D.hpp>

namespace BuilderTest
{
    class TestWorldOne : public Tower::World
    {
    public:
        TestWorldOne();

        ~TestWorldOne() final;

        void v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance) final;

        void v_Update(F32 delta) final;


    private:
        // Where do we live?
        // Where is out code/behavior defined?
        Box2D _background;
        Box2D _redBox;
        Box2D _greenBox;
        Box2D _blueBox;
        Tower::p_Camera2D _camera2d;
        // Why am I here, but not the camera itself?
        F32 _cameraMoveSpeed;

        void _CheckInput(void);
    };
}