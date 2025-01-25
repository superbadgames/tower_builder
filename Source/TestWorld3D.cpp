#include "pch.h"
#include "BuilderTest/Worlds/TestWorld3D.hpp"

using namespace BuilderTest;

TestWorld3D::TestWorld3D(void) :
    _box3d(),
    _viewMatrix(1.0f)
{

}


TestWorld3D::~TestWorld3D(void)
{

}


void TestWorld3D::v_Init(void)
{
    _box3d.Init();

    _viewMatrix = glm::translate(_viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
}


void TestWorld3D::v_Update(void)
{

}


void TestWorld3D::v_Render(void)
{
    // Render 3D cube
    _box3d.Draw(_viewMatrix);
}
