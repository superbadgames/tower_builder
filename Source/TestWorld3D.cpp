#include "pch.h"
#include "BuilderTest/Worlds/TestWorld3D.hpp"

using namespace BuilderTest;

TestWorld3D::TestWorld3D(void) :
    _boxes(),
    _camera(),
    _mouseOn(true)
{

}


TestWorld3D::~TestWorld3D(void)
{

}


void TestWorld3D::v_Init(void)
{
    glm::vec3 position{ 0.0f, 0.0f, -30.0f };
    F32 yPos = 45.0f;
    F32 zPos = 65.0f;
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Init();
        _boxes[i].SetPosition(position);

        position.x += 30.0f;

        if (position.x <= 90.0f)
        {
            position.x = 0.0f;
        }

        position.y += yPos;
        // yPos *= -1.0f;
        position.z += zPos;
        //zPos *= -1.0f;
    }

    _camera.Init();

    Tower::Director::Instance()->GetWindowPointer()->HideMouseCursor();
    _mouseOn = false;
}


void TestWorld3D::v_Update(void)
{
    F32 delta = Tower::Director::Instance()->GetDeltaTime();
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Update(delta);
    }

    if (Tower::InputManager::Instance()->IsBindingPressed("toggleMouse"))
    {
        if (_mouseOn)
        {
            Tower::Director::Instance()->GetWindowPointer()->HideMouseCursor();
            _mouseOn = false;
        }
        else
        {
            Tower::Director::Instance()->GetWindowPointer()->ShowMouseCursor();
            _mouseOn = true;
        }
    }

    F32 cameraMovSpeed = 50.0f;
    if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_forward"))
    {
        _camera.MoveForward(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_back"))
    {
        _camera.MoveBack(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_right"))
    {
        _camera.MoveRight(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_left"))
    {
        _camera.MoveLeft(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("up"))
    {
        _camera.MoveUp(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("down"))
    {
        _camera.MoveDown(cameraMovSpeed * delta);
    }

    _camera.Update(delta);
}


void TestWorld3D::v_Render(void)
{
    // Render 3D cube
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Draw(_camera.GetViewMatrix());
    }
}
