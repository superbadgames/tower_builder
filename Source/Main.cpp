#include "pch.h"
#include <Tower/framework.h>

#include "BuilderTest/Worlds/TestWorld1.hpp"
#include "BuilderTest/Worlds/TestWorld3D.hpp"

#include <Tower/Components/World.hpp>
#include <Tower/Managers/Director.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Rendering/Texture.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>
#include <Tower/Input/InputManager.hpp>
#include <Tower/Cameras/Camera2D.hpp>
#include <Tower/UI/Glyph.hpp>


#include <iostream>
#include <bitset>

int main(void)
{
    // TODO: This should come from a config file
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;

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
    inputManager->AddArrowMovement("camera_move_up", "camera_move_down", "camera_move_right", "camera_move_left");
    inputManager->AddBinding("reset_position", Tower::InputButton::SPACE);
    inputManager->AddBinding("red_box", Tower::InputButton::NUM_1);
    inputManager->AddBinding("green_box", Tower::InputButton::NUM_2);
    inputManager->AddBinding("blue_box", Tower::InputButton::NUM_3);

    inputManager->AddBinding("move_forward", Tower::InputButton::W);
    inputManager->AddBinding("move_back", Tower::InputButton::S);
    inputManager->AddBinding("up", Tower::InputButton::E);
    inputManager->AddBinding("down", Tower::InputButton::Q);

    inputManager->AddBinding("toggleMouse", Tower::InputButton::ENTER);

    //
    // Initialize shaders
    //
    Tower::p_Shader glyphShader = std::make_shared<Tower::Shader>();
    glyphShader->Load("..\\..\\Assets\\Default\\Shaders\\ui_text_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\ui_text_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader(1, glyphShader);

    Tower::p_Shader spriteShader = std::make_shared<Tower::Shader>();
    spriteShader->Load("..\\..\\Assets\\Default\\Shaders\\sprite_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\sprite_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader(2, spriteShader);

    Tower::p_Shader basic3dShader = std::make_shared<Tower::Shader>();
    basic3dShader->Load("..\\..\\Assets\\Default\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\basic_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader(3, basic3dShader);


    //
    // Initialize Textures
    //
    Tower::TextureManager::Instance()->LoadTexture(1, "..\\..\\Assets\\Textures\\Boxes\\box_red_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(2, "..\\..\\Assets\\Textures\\Boxes\\box_green_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(3, "..\\..\\Assets\\Textures\\Boxes\\box_blue_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(4, "..\\..\\Assets\\Textures\\Boxes\\box_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(5, "..\\..\\Assets\\Textures\\brick.png");
    Tower::TextureManager::Instance()->LoadTexture(6, "..\\..\\Assets\\Textures\\Boxes\\brown_background.png");
    Tower::TextureManager::Instance()->LoadTexture(7, "..\\..\\Assets\\Default\\Textures\\cube_test_bigger.png");
    Tower::TextureManager::Instance()->LoadTexture(8, "..\\..\\Assets\\Textures\\Simulator\\Zipper_texture.png");
    Tower::TextureManager::Instance()->LoadTexture(9, "..\\..\\Assets\\Textures\\Simulator\\Simulator_Asteroid_v1.png");
    Tower::TextureManager::Instance()->LoadTexture(10, "..\\..\\Assets\\Textures\\Simulator\\Simulator_Mine.png");
    Tower::TextureManager::Instance()->LoadTexture(11, "..\\..\\Assets\\Textures\\Simulator\\Simulator_Wall.png");


    BuilderTest::TestWorldOne worldOne{};
    worldOne.v_Init();

    BuilderTest::TestWorld3D world3D{};
    world3D.v_Init();

    while (!director->ShouldProgramClose())
    {
        director->StartFrame();

        if (inputManager->IsBindingPressed("exit"))
        {
            director->CloseProgram();
        }

        // worldOne.v_Update();
        // worldOne.v_Render();

        world3D.v_Update();
        world3D.v_Render();

        director->EndFrame();
    }


    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}