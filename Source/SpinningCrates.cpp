#include "pch.h"
#include "Soyokaze/Worlds/SpinningCrates.hpp"
#include <iostream>

using namespace Soyokaze;

SpinningCrates::SpinningCrates(void) :
    _controller(nullptr),
    _camera(nullptr),
    _crates3D(),
    _crate2D_1(),
    _crate2D_2(),
    _blueColor(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)),
    _redColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)),
    _angle1(0.0f),
    _angle2(0.0f),
    _offset(0.0f),
    _direction(1.0f),
    _cameraDeadZone(1.0f),
    _firstMouseMove(true),
    _moveCamera(false)
{

}

SpinningCrates::~SpinningCrates(void)
{
    _crates3D.clear();
}

void SpinningCrates::v_Init(Tower::p_Director director)
{
    std::cout << "spinning crates init called\n";
    _director = director;
    // Set up data
    Tower::p_Shader shaderPtr = _director->GetShaderManager()->GetShader(1);
    glm::vec3 rotAngle = glm::vec3(0.0f, 1.0f, 0.0f);
    _angle1 = 55.0f;
    _angle2 = 305.0f;
    F32 cubeScale = 0.5f;
    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    // Configure sprites
    _crate2D_1.AddTransform();
    _crate2D_1.AddSprite(shaderPtr, _director->GetTextureManager()->GetTexture(1));
    _crate2D_1.SetColor(_blueColor);
    _crate2D_1.SetScale(glm::vec3(0.5, 0.5f, 0.5f));
    _crate2D_1.SetRotationAxisAndAngle(_angle1, rotAngle);
    _crate2D_1.SetPosition(glm::vec3(-1.0f, 0.0f, 0.0f));

    _crate2D_2.AddTransform();
    _crate2D_2.AddSprite(shaderPtr, _director->GetTextureManager()->GetTexture(1));
    _crate2D_2.SetColor(_redColor);
    _crate2D_2.SetScale(glm::vec3(0.5, 0.5f, 0.5f));
    _crate2D_2.SetRotationAxisAndAngle(_angle2, rotAngle);
    _crate2D_2.SetPosition(glm::vec3(1.0f, 0.0f, 0.0f));


    // configure cubes
    for (U32 i = 0; i < 10; i++)
    {
        _crates3D.push_back(Crate3D());
        _crates3D[i].Init(shaderPtr);
        _crates3D[i].SetPosition(cubePositions[i]);
        _crates3D[i].SetScale(glm::vec3(cubeScale));
    }

    // Controller setup
    _controller = make_shared<Tower::InputController>();
    _controller->AddKeyboardBinding("quit", Tower::InputButton::ESCAPE, Tower::InputButtonState::PRESS);
    _controller->AddWASDMovement();
    _controller->AddMouseBinding("move_camera", Tower::InputButton::RIGHT_CLICK, Tower::InputButtonState::PRESS);
    _controller->AddMouseBinding("stop_move_camera", Tower::InputButton::RIGHT_CLICK, Tower::InputButtonState::RELEASE);
    _controller->AddMouseBinding("check_screen_location", Tower::InputButton::LEFT_CLICK, Tower::InputButtonState::RELEASE);
    _controller->AddKeyboardBinding("increase_mouse_dead_zone", Tower::InputButton::UP_ARROW, Tower::InputButtonState::PRESS);
    _controller->AddKeyboardBinding("decrease_mouse_dead_zone", Tower::InputButton::DOWN_ARROW, Tower::InputButtonState::PRESS);

    _director->RegisterInputWithWindow(_controller);

    // Set background color
    glm::vec3 windowBackgroundColor{ 0.2f, 0.2f, 0.2f };

    _director->SetWindowBackgroundColor(windowBackgroundColor);

    // Configure camera
    U32 width = (U32)_director->GetWindowPointer()->GetScreenWidth();
    U32 height = (U32)_director->GetWindowPointer()->GetScreenHeight();

    _camera = make_shared<Tower::Camera>();
    _camera->Init(90.0f, width, height, 0.1f, 100.0f);
    //camera->SetViewMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f)));
    _camera->SetMovementSpeed(25.0f);



    // The shader needs to be updated with the camera's new projection matrix
    shaderPtr->SetUniform("view", _camera->GetViewMatrix());
    shaderPtr->SetUniform("projection", _camera->GetProjectionMatrix());
    shaderPtr->SetUniform("light_color", glm::vec4(1.0f, 0.5f, 0.31f, 1.0f));
}

void SpinningCrates::v_Update(void)
{
    //
    // START OF LOOP ACTIONS
    //
    _director->BeginUpdate();
    F32 delta = _director->GetDeltaTime();

    //
    // SHOULD MOVE CAMERA INPUT LOOP
    //
    if (_controller->IsKeyboardBindingActive("quit"))
    {
        _director->CloseProgram();
    }

    if (_controller->IsMouseBindingActive("move_camera"))
    {
        _moveCamera = true;
        // _director->GetWindowPointer()->HideMouseCursor();
    }

    if (_controller->IsMouseBindingActive("stop_move_camera"))
    {
        _moveCamera = false;
        //_director->GetWindowPointer()->ShowMouseCursor();
    }


    if (_controller->IsKeyboardBindingActive("increase_mouse_dead_zone"))
    {
        _cameraDeadZone += 0.1f;
        std::cout << "camera dead zone is now " << _cameraDeadZone << std::endl;
    }

    if (_controller->IsKeyboardBindingActive("decrease_mouse_dead_zone"))
    {
        _cameraDeadZone -= 0.1f;
        std::cout << "camera dead zone is now " << _cameraDeadZone << std::endl;
    }

    //
    // CAMERA LOOK LOOP
    //
    if (_moveCamera)
    {
        const glm::vec2& prevMouse = _controller->GetMousePreviousCursorPosition();
        const glm::vec2& curMouse = _controller->GetMouseCurrentCursorPosition();

        std::cout << "previous Mouse = (" << prevMouse.x << "," << prevMouse.y << ")" << std::endl
            << "current Mouse = (" << curMouse.x << "," << curMouse.y << ")" << std::endl;



        // if (_firstMouseMove)
        // {
        //     prevMouse = _controller->GetMouseCurrentCursorPosition();
        //     _firstMouseMove = false;
        // }

        F32 xOffset = curMouse.x - prevMouse.x;
        F32 yOffset = prevMouse.y - curMouse.y;
        //offset.x = curMouse.x - prevMouse.x;
        // Reversed because the screen maps space different?
        //offset.y = prevMouse.y - curMouse.y;
        //std::cout << "\r" << "offset: (" << offset.x << "," << offset.y << "\t\t\t\tlength: " << offset.length() << std::flush;
        //if (offset.length() >= _cameraDeadZone)
        //{

        // std::cout << std::fixed;
        // std::cout << std::setprecision(5);
        // std::cout << "==========================================================" << std::endl
        //     << "prevMouse: (" << prevMouse.x << "," << prevMouse.y << ")" << std::endl
        //     << "curMouse: (" << curMouse.x << "," << curMouse.y << ")" << std::endl
        //     << "offset: (" << offset.x << "," << offset.y << ")" << std::endl
        //     << "Offset length: " << offset.length() << std::endl;


       // _camera->MouseControl(xOffset, yOffset);


        //}
        if (_controller->IsMouseBindingActive("check_screen_location"))
        {
            const glm::vec2 mousePos = _controller->GetMouseCurrentCursorPosition();

            std::cout << "Mouse Position: (" << mousePos.x << "," << mousePos.y << ")\n";
        }

    }

    //
    // UPDATE CAMERA MOVEMENT LOOP
    //
    if (_controller->IsKeyboardBindingActive("move_forward"))
    {
        _camera->MoveForward(delta);
    }
    else if (_controller->IsKeyboardBindingActive("move_back"))
    {
        _camera->MoveBack(delta);
    }
    else if (_controller->IsKeyboardBindingActive("move_right"))
    {
        _camera->MoveRight(delta);
    }
    else if (_controller->IsKeyboardBindingActive("move_left"))
    {
        _camera->MoveLeft(delta);
    }


    //
    // CAMERA UPDATE
    //
    _camera->CalculateViewMatrix();

    //
    // 2D OBJECT UPDATE
    //
    _offset += delta * _direction;

    _angle1 += 1.0f;
    _angle2 -= 1.0f;

    if (_angle1 > 360.0f)
    {
        _angle1 = 0.0f;
    }

    if (_angle2 < -360.0f)
    {
        _angle2 = 0.0f;
    }

    _crate2D_1.SetRotationAngle(_angle1);
    _crate2D_2.SetRotationAngle(_angle2);

    if (_offset >= 1.0f || _offset <= -1.0f)
    {
        _direction *= -1.0f;
    }

    glm::vec3 cratePos = _crate2D_1.GetPosition();
    cratePos.y = _offset;
    _crate2D_1.SetPosition(cratePos);

    cratePos = _crate2D_2.GetPosition();
    cratePos.y = -_offset;
    _crate2D_2.SetPosition(cratePos);

    _crate2D_1.Update(delta);
    _crate2D_2.Update(delta);

    for (U32 i = 0; i < _crates3D.size(); i++)
    {
        _crates3D[i].Update(delta, (F32)i);
    }

    //
    // END OF LOOP ACTIONS
    //
    _controller->ResetAllBindingStates();
    _director->EndUpdate();
}

void SpinningCrates::v_Render(void)
{
    glm::mat4 viewMatrix = _camera->GetViewMatrix();

    _crate2D_1.Draw(viewMatrix);
    _crate2D_2.Draw(viewMatrix);

    //
    // UPDATE AND DRAW ALL OBJECTS
    //
    for (U32 i = 0; i < _crates3D.size(); i++)
    {
        _crates3D[i].Draw(viewMatrix
        );
    }
}