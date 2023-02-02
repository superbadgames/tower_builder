#include "pch.h"
#include "framework.hpp"
#include "Lateralus/Crate3D.hpp"
#include <Tower/Managers/Director.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Rendering/Texture.hpp>
#include <Tower/Components/Camera.hpp>
#include <Tower/Entity.hpp>
#include <Tower/Input/InputController.hpp>

#include <GLFW/glfw3.h>

#include <iostream>

using Lateralus::Crate3D;

Tower::p_Director director;
Tower::p_Camera camera;

Tower::p_Texture containerTexture;
Tower::p_InputController controller;

void GameLogic(void)
{
    //
    // 2D CRATES
    //
    Tower::Entity crate{};
    crate.AddTransform();
    crate.AddSprite(director->GetShader("basic"), containerTexture);

    Tower::Entity crate2{};
    crate2.AddTransform();
    crate2.AddSprite(director->GetShader("basic"), containerTexture);

    glm::vec4 blueColor = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
    glm::vec4 redColor = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

    crate.SetColor(blueColor);
    crate2.SetColor(redColor);

    crate.SetScale(glm::vec3(0.5, 0.5f, 0.5f));
    crate2.SetScale(glm::vec3(0.5, 0.5f, 0.5f));

    glm::vec3 rotAngle = glm::vec3(0.0f, 1.0f, 0.0f);

    F32 angle1 = 55.0f;
    F32 angle2 = 305.0f;

    crate.SetRotationAxisAndAngle(angle1, rotAngle);
    crate2.SetRotationAxisAndAngle(angle2, rotAngle);

    crate.SetPosition(glm::vec3(-1.0f, 0.0f, 0.0f));
    crate2.SetPosition(glm::vec3(1.0f, 0.0f, 0.0f));

    F32 offset = 0.0f;
    F32 direction = 1.0f;

    //
    // CUBES
    //
    F32 scale = 0.5f;

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
        glm::vec3(-1.3f, 1.0f, -1.5f) };

    std::vector<Crate3D> crates;

    for (U32 i = 0; i < 10; i++)
    {
        crates.push_back(Crate3D());
        crates[i].Init(director->GetShader("basic"));
        crates[i].SetPosition(cubePositions[i]);
        crates[i].SetScale(glm::vec3(scale));
    }

    bool firstMouseMove = true;
    bool moveCamera = false;

    //
    // BEGIN WHILE LOOP
    //
    while (!director->ShouldProgramClose())
    {
        //
        // START OF LOOP ACTIONS
        //
        director->Tick();
        director->ProcessEvents();
        F32 delta = director->GetDeltaTime();

        //
        // SHOULD MOVE CAMERA INPUT LOOP
        //
        if (controller->IsKeyboardBindingActive("quit"))
        {
            director->CloseProgram();
        }

        if (controller->IsMouseBindingActive("move_camera"))
        {
            moveCamera = true;
            director->GetWindowPointer()->HideMouseCursor();
        }

        if (controller->IsMouseBindingActive("stop_move_camera"))
        {
            std::cout << "Mouse Release happened\n";
            moveCamera = false;
            director->GetWindowPointer()->ShowMouseCursor();
        }

        //
        // CAMERA LOOK LOOP
        //
        if (moveCamera)
        {
            const glm::vec2& prevMouse = controller->GetMousePreviousCursorPosition();
            const glm::vec2& curMouse = controller->GetMouseCurrentCursorPosition();
            // if (firstMouseMove)
            // {
            //     prevMouse = controller->GetMouseCurrentCursorPosition();
            //     firstMouseMove = false;
            // }
            glm::vec2 offset;
            offset.x = curMouse.x - prevMouse.x;
            offset.y = prevMouse.y - curMouse.y;

            camera->UpdateYaw(offset.x);
            camera->UpdatePitch(offset.y);

        }

        //
        // UPDATE CAMERA MOVEMENT LOOP
        //
        if (controller->IsKeyboardBindingActive("move_forward"))
        {
            camera->MoveForward(delta);
        }
        else if (controller->IsKeyboardBindingActive("move_back"))
        {
            camera->MoveBack(delta);
        }
        else if (controller->IsKeyboardBindingActive("move_right"))
        {
            camera->MoveRight(delta);
        }
        else if (controller->IsKeyboardBindingActive("move_left"))
        {
            camera->MoveLeft(delta);
        }


        //
        // CAMERA UPDATE
        //
        camera->CalculateViewMatrix();

        //
        // 2D OBJECT UPDATE
        //
        offset += delta * direction;

        angle1 += 1.0f;
        angle2 -= 1.0f;

        if (angle1 > 360.0f)
        {
            angle1 = 0.0f;
        }

        if (angle2 < -360.0f)
        {
            angle2 = 0.0f;
        }

        crate.SetRotationAngle(angle1);
        crate2.SetRotationAngle(angle2);

        if (offset >= 1.0f || offset <= -1.0f)
        {
            direction *= -1.0f;
        }

        glm::vec3 cratePos = crate.GetPosition();
        cratePos.y = offset;
        crate.SetPosition(cratePos);

        cratePos = crate2.GetPosition();
        cratePos.y = -offset;
        crate2.SetPosition(cratePos);

        crate.Update(director->GetDeltaTime());
        crate2.Update(director->GetDeltaTime());

        // blueColor.z = real_sin(director->GetElapsedTime()) / 2.0f + 0.5f;

        // crate.GetSprite()->SetColor(blueColor);
        // crate.GetModel()->SetColor(blueColor);

        crate.Draw();
        crate2.Draw();

        //
        // SHADER UPDATE
        //
        // TODO: this pattern sucks a lot. I need a better way to get this done...
        // I don't want to have to call this every fucking frame for every fucking
        // shader. That would be a pain to remember, but this has to happen, or the
        // view will never update.
        director->GetShader("basic")->SetUniform("view", camera->GetViewMatrix());

        //
        // UPDATE AND DRAW ALL OBJECTS
        //
        for (U32 i = 0; i < crates.size(); i++)
        {
            crates[i].Update(delta, (F32)i);
            crates[i].Draw();
        }

        //
        // END OF LOOP ACTIONS
        //
        director->Tock();
        controller->ResetAllBindingStates();
    }
}

int main(void)
{
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;

    director = Tower::Director::Instance();

    if (!director->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    std::cout << "We are up and running!" << std::endl;
    controller = std::make_shared<Tower::InputController>();
    controller->AddKeyboardBinding("quit", Tower::InputButton::ESCAPE, Tower::InputButtonState::PRESS);
    controller->AddWASDMovement();
    controller->AddMouseBinding("move_camera", Tower::InputButton::RIGHT_CLICK, Tower::InputButtonState::PRESS);
    controller->AddMouseBinding("stop_move_camera", Tower::InputButton::RIGHT_CLICK, Tower::InputButtonState::RELEASE);

    director->SetInput(controller);

    glm::vec3 windowBackgroundColor{ 0.2f, 0.2f, 0.2f };

    director->SetWindowBackgroundColor(windowBackgroundColor);

    Tower::p_Shader shader = std::make_shared<Tower::Shader>();
    shader->Load("..\\..\\Assets\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Shaders\\basic_fragment.glsl");

    containerTexture = std::make_shared<Tower::Texture>();
    containerTexture->Load("..\\..\\Assets\\Textures\\container.jpg");

    camera = std::make_shared<Tower::Camera>();
    camera->Init(45.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.1f, 100.0f);
    // I need to fix the constructor first. The up, yaw and pitch aren't set yet.
    camera->SetPosition(glm::vec3(0.0f, 0.0f, -25.0f));
    //camera->SetViewMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f)));
    camera->SetMovementSpeed(25.0f);

    // TODO: Something is going to have to know how to call this.
    // MOve this into a World::v_Init
    shader->SetUniform("view", camera->GetViewMatrix());
    shader->SetUniform("projection", camera->GetProjectionMatrix());
    shader->SetUniform("light_color", glm::vec4(1.0f, 0.5f, 0.31f, 1.0f));

    // TODO TOMORROW:
    // try to use a ShaderManager that is local to this file
    director->GetShaderManager()->RegisterShader("basic", shader);

    GameLogic();

    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}