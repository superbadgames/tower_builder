#include "pch.h"
#include "BuilderTest/Worlds/TestWorld3D.hpp"

using namespace BuilderTest;

TestWorld3D::TestWorld3D(void) :
    _boxes(),
    _coloredCube(),
    _theZipper(),
    _wall(),
    _mine(),
    _camera3d(nullptr),
    _mouseOn(true)
{

}


TestWorld3D::~TestWorld3D(void)
{

}


void TestWorld3D::v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance)
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

    _coloredCube.Init("..\\..\\Assets\\Default\\CubeModel\\cube.glb", "cube_test_bigger");
    _coloredCube.SetPosition(glm::vec3(0.0f, 0.0f, 30.0f));

    _theZipper.Init("..\\..\\Assets\\Models\\Simulator\\zipper_v1.glb", "the_zipper");
    _theZipper.SetPosition(glm::vec3(0.0f, -100.0f, -150.0f));

    _wall.Init("..\\..\\Assets\\Models\\Simulator\\simulator_wall_v1.glb", "wall_v1");
    _wall.SetPosition(glm::vec3(100.0f, -100.0f, 0.0f));

    _mine.Init("..\\..\\Assets\\Models\\Simulator\\simulator_spike_mine_v1.glb", "mine_v1");
    _mine.SetPosition(glm::vec3(200.0f, -100.0f, 0.0f));

    _camera3d = std::make_shared<Tower::Camera3D>();
    _camera3d->v_Init(screenWidth, screenHeight, fov, viewDistance);
    _camera = _camera3d;

    Tower::Director::Instance()->HideMouseCursor();
    _mouseOn = false;
}


void TestWorld3D::v_Update(F32 delta)
{
    for (U32 i = 0; i < NUM_BOXES; ++i)
    {
        _boxes[i].Update(delta);
    }

    if (Tower::InputManager::Instance()->IsBindingPressed("toggleMouse"))
    {
        if (_mouseOn)
        {
            Tower::Director::Instance()->HideMouseCursor();
            _mouseOn = false;
        }
        else
        {
            Tower::Director::Instance()->ShowMouseCursor();
            _mouseOn = true;
        }
    }

    F32 cameraMovSpeed = 50.0f;
    if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_forward"))
    {
        _camera3d->MoveForward(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_back"))
    {
        _camera3d->MoveBack(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_right"))
    {
        _camera3d->MoveRight(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_left"))
    {
        _camera3d->MoveLeft(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("up"))
    {
        _camera3d->MoveUp(cameraMovSpeed * delta);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("down"))
    {
        _camera3d->MoveDown(cameraMovSpeed * delta);
    }

    _camera3d->Update(delta);

    _theZipper.Update(delta);
}
