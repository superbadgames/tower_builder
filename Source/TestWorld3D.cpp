#include "pch.h"
#include "BuilderTest/Worlds/TestWorld3D.hpp"

using namespace BuilderTest;

TestWorld3D::TestWorld3D(void) :
    _boxes(),
    _viewMatrix(1.0f)
{

}


TestWorld3D::~TestWorld3D(void)
{

}


void TestWorld3D::v_Init(void)
{
    glm::vec3 position{ 0.0f, 0.0f, -30.0f };
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Init();
        _boxes[i].SetPosition(position);

        position.x += 30.0f;

        if (position.x <= 90.0f)
        {
            position.x = 0.0f;
            position.y += 45.0f;
            position.z -= 65.0f;
        }
    }

    _viewMatrix = glm::translate(_viewMatrix, glm::vec3(0.0f, 0.0f, -10.0f));
}


void TestWorld3D::v_Update(void)
{
    F32 delta = Tower::Director::Instance()->GetDeltaTime();
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Update(delta);
    }
}


void TestWorld3D::v_Render(void)
{
    // Render 3D cube
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Draw(_viewMatrix);
    }
}
