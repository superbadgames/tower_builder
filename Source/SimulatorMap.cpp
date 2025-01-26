#include "pch.h"
#include "Simulator/SimulatorMap.hpp"

using namespace Simulator;

SimulatorMap::SimulatorMap(void) :
    _wallsLeft(),
    _wallsRight(),
    _mines(),
    _editorCamera(),
    _zipperCamera(),
    _theZipper(),
    _editorCameraMoveSpeed(50.0f),
    _mouseOn(true),
    _builderInControl(false)
{

}


SimulatorMap::~SimulatorMap(void)
{

}


void SimulatorMap::v_Init(void)
{
    Tower::Director::Instance()->GetWindowPointer()->SetColor(glm::vec3(0.1f, 0.1f, 0.3f));

    _editorCamera.Init();

    _zipperCamera.SetOffset(glm::vec2(300.0f, 85.0f));

    _theZipper.Init(glm::vec3(0.0f));

    F32 distance = 300.0f;
    glm::vec3 nextPositionLeft = glm::vec3(distance, 0.0f, distance);
    glm::vec3 nextPositionRight = glm::vec3(-distance, 0.0f, distance);

    Tower::AxisAngle wallRotation{};
    wallRotation.axis = glm::vec3(0.0f, 0.0f, 1.0f);
    wallRotation.angle = 90.0f;

    glm::vec3 wallScale(100.0f, 20.0f, 75.0f);

    for (U32 i = 0; i < NUM_WALLS; ++i)
    {
        _wallsLeft[i].Init(nextPositionLeft);
        _wallsLeft[i].SetRotation(wallRotation);
        _wallsLeft[i].SetScale(wallScale);
        _wallsLeft[i].Activate();

        _wallsRight[i].Init(nextPositionRight);
        _wallsRight[i].SetRotation(wallRotation);
        _wallsRight[i].SetScale(wallScale);
        _wallsRight[i].Activate();

        nextPositionLeft.z += distance;
        nextPositionRight.z += distance;
    }

    distance = 200.0f;
    nextPositionLeft = glm::vec3(10.0f, 50.0f, distance);

    for (U32 i = 0; i < NUM_MINES; ++i)
    {
        _mines[i].Init(nextPositionLeft);
        U32 randomSpeed = std::rand() % 100 + 15;
        _mines[i].SetMoveSpeed((F32)randomSpeed);

        U32 headOrTails = std::rand() % 2;

        if (headOrTails == 1)
        {
            _mines[i].SetMoveSide();
        }
        else
        {
            _mines[i].SetMoveUp();
        }

        _mines[i].Activate();
        nextPositionLeft.z += distance;
    }

    _mouseOn = false;
}


void SimulatorMap::v_Update(void)
{
    F32 delta = Tower::Director::Instance()->GetDeltaTime();


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

    if (Tower::InputManager::Instance()->IsBindingPressed("swapControls"))
    {
        if (_builderInControl)
        {
            _builderInControl = false;
            _theZipper.ActivateControls();
        }
        else
        {
            _builderInControl = true;
            _theZipper.DeactivateControl();
        }
    }

    if (_builderInControl)
    {
        if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_forward"))
        {
            _editorCamera.MoveForward(_editorCameraMoveSpeed * delta);
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_back"))
        {
            _editorCamera.MoveBack(_editorCameraMoveSpeed * delta);
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_right"))
        {
            _editorCamera.MoveRight(_editorCameraMoveSpeed * delta);
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_left"))
        {
            _editorCamera.MoveLeft(_editorCameraMoveSpeed * delta);
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("up"))
        {
            _editorCamera.MoveUp(_editorCameraMoveSpeed * delta);
        }
        else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("down"))
        {
            _editorCamera.MoveDown(_editorCameraMoveSpeed * delta);
        }

        _editorCamera.Update(delta);
    }
    else
    {
        _zipperCamera.Update(_theZipper.GetPosition(), glm::vec3(0.0f, 1.0f, 0.0f), _theZipper.GetForward());
    }

    _theZipper.Update(delta);

    for (U32 i = 0; i < NUM_MINES; ++i)
    {
        _mines[i].Update(delta);
    }
}


void SimulatorMap::v_Render(void)
{
    glm::mat4 viewMatrix{};
    if (_builderInControl)
    {
        viewMatrix = _editorCamera.GetViewMatrix();
    }
    else
    {
        viewMatrix = _zipperCamera.GetViewMatrix();
    }

    _theZipper.Draw(viewMatrix);

    for (U32 i = 0; i < NUM_WALLS; ++i)
    {
        _wallsLeft[i].Draw(viewMatrix);
        _wallsRight[i].Draw(viewMatrix);
    }

    for (U32 i = 0; i < NUM_MINES; ++i)
    {
        _mines[i].Draw(viewMatrix);
    }
}
