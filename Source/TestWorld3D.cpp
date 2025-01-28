#include "pch.h"
#include "BuilderTest/Worlds/TestWorld3D.hpp"

using namespace BuilderTest;

TestWorld3D::TestWorld3D(void) :
    _boxes(),
    _coloredCube(),
    _theZipper(),
    _wall(),
    _mine(),
    _camera(),
    _mouseOn(true)
{

}


TestWorld3D::~TestWorld3D(void)
{

}


void TestWorld3D::v_Init(void)
{
    glm::vec3 position{ 30.0f, 0.0f, -30.0f };
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

    _coloredCube.Init("..\\..\\Assets\\Default\\CubeModel\\cube.glb", 7);
    _coloredCube.SetPosition(glm::vec3(0.0f, 0.0f, 30.0f));

    _theZipper.Init("..\\..\\Assets\\Models\\Simulator\\zipper_v1.glb", 8);
    _theZipper.SetPosition(glm::vec3(0.0f, -100.0f, -150.0f));

    _wall.Init("..\\..\\Assets\\Models\\Simulator\\simulator_wall_v1.glb", 11);
    _wall.SetPosition(glm::vec3(100.0f, -100.0f, 0.0f));

    _mine.Init("..\\..\\Assets\\Models\\Simulator\\simulator_spike_mine_v1.glb", 10);
    _mine.SetPosition(glm::vec3(200.0f, -100.0f, 0.0f));

    _camera.Init(Tower::Director::Instance()->GetPerspectiveMatrix());

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

    _theZipper.Update(delta);
}


void TestWorld3D::v_Render(void)
{
    // Render 3D cube
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Draw(_camera.GetViewMatrix());
    }
    _coloredCube.Draw(_camera.GetViewMatrix());
    _theZipper.Draw(_camera.GetViewMatrix());
    _wall.Draw(_camera.GetViewMatrix());
    _mine.Draw(_camera.GetViewMatrix());
}
