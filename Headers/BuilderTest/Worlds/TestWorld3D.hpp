#pragma once
#include "pch.h"
#include <Tower/framework.h>

#include "BuilderTest/Entities/Box3D.hpp"

#include <Tower/Components/Map.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Cameras/Camera3D.hpp>

#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
//#include <random>

namespace BuilderTest
{
    class TestWorld3D : public Tower::I_Map
    {
    public:
        TestWorld3D(void);

        ~TestWorld3D(void) final;

        void v_Init(void) final;

        void v_Update(void) final;

        void v_Render(void) final;
    private:
        static const U32 NUM_BOXES = 10;
        Box3D _boxes[NUM_BOXES];
        Tower::Camera3D _camera;
        bool _mouseOn;
    };
}