#pragma once
#include "pch.h"
#include <Tower/framework.h>
#include "BuilderTest/Entities/Box3D.hpp"
#include "BuilderTest/Entities/Object3D.hpp"

#include <Tower/Components/World.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Managers/ModelManager.hpp>
#include <Tower/Cameras/Camera3D.hpp>

#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
//#include <random>

namespace BuilderTest
{
    class TestWorld3D : public Tower::World
    {
    public:
        TestWorld3D(void);

        ~TestWorld3D(void) final;

        void v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance) final;

        void v_Update(F32 delta) final;

    private:
        static const U32 NUM_BOXES = 106;
        Box3D _boxes[NUM_BOXES];
        Object3D _coloredCube;
        Object3D _theZipper;
        Object3D _wall;
        Object3D _mine;
        Tower::p_Camera3D _camera3d;
        bool _mouseOn;
    };
}