#include "pch.h"
#include <Tower/framework.h>
#include "BuilderTest/Worlds/TestWorld1.hpp"
#include <Tower/Components/World.hpp>
#include <Tower/Managers/Director.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Rendering/Texture.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Input/InputManager.hpp>
#include <Tower/Cameras/Camera2D.hpp>


#include <iostream>
#include <bitset>

int main(void)
{
    // TODO: This should come from a config file
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;
    const U32 BASIC_SHADER_ID = 1;

    Tower::p_Director director = Tower::Director::Instance();

    if (!director->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    Tower::p_InputManager inputManager = Tower::InputManager::Instance();

    // Set up key bindings
    inputManager->AddBinding("exit", Tower::InputButton::ESCAPE);
    inputManager->AddWASDMovement("move_up", "move_down", "move_right", "move_left");
    inputManager->AddBinding("reset_position", Tower::InputButton::SPACE);

    //
    // Initialize shaders
    //
    // Tower::p_Shader basicShader = std::make_shared<Tower::Shader>();
    // basicShader->Load("..\\..\\Assets\\Default\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\basic_fragment.glsl");
    // director->GetShaderManager()->RegisterShader(BASIC_SHADER_ID, basicShader);

    Tower::p_Shader spriteShader = std::make_shared<Tower::Shader>();
    spriteShader->Load("..\\..\\Assets\\Default\\Shaders\\sprite_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\sprite_fragment.glsl");
    director->GetShaderManager()->RegisterShader(2, spriteShader);


    //
    // Initialize Textures
    //
    director->GetTextureManager()->LoadTexture(1, "..\\..\\Assets\\Textures\\Boxes\\box_red_8x8.png");
    director->GetTextureManager()->LoadTexture(2, "..\\..\\Assets\\Textures\\Boxes\\box_green_8x8.png");
    director->GetTextureManager()->LoadTexture(3, "..\\..\\Assets\\Textures\\Boxes\\box_blue_8x8.png");
    director->GetTextureManager()->LoadTexture(4, "..\\..\\Assets\\Textures\\Boxes\\box_8x8.png");
    director->GetTextureManager()->LoadTexture(5, "..\\..\\Assets\\Textures\\brick.png");

    // TODO: Work on this later. Pausing UI for now
    //Tower::p_Font font = std::make_shared<Tower::Font>();
    //font->Load("..\\..\\Assets\\Default\\Fonts\\PressStart2P-Regular.tff", 48);

    //Tower::p_World spinningCratesWorld = make_shared<Soyokaze::SpinningCrates>();
    //spinningCratesWorld->v_Init(director);

    BuilderTest::TestWorldOne worldOne{};
    worldOne.v_Init(director);

    Tower::Camera2D camera{};
    camera.Init(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (!director->ShouldProgramClose())
    {
        director->StartFrame();

        if (inputManager->IsBindingPressed("exit"))
        {
            director->CloseProgram();
        }

        worldOne.v_Update();
        worldOne.v_Render(camera.GetViewMatrix());


        director->EndFrame();
    }


    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}