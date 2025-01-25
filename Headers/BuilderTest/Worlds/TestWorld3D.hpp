#pragma once
#include "pch.h"
#include <Tower/framework.h>

#include "BuilderTest/Entities/Box3D.hpp"

#include <Tower/Components/Map.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>

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
        Box3D _box3d;
        glm::mat4 _viewMatrix;
    };
}