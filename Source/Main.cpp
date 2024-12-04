#include "pch.h"
#include <Tower/framework.h>
#include "BuilderTest/Worlds/TestWorld1.hpp"
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

    //
    // Initialize shaders
    //
    Tower::p_Shader glyphShader = std::make_shared<Tower::Shader>();
    glyphShader->Load("..\\..\\Assets\\Default\\Shaders\\ui_text_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\ui_text_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader(1, glyphShader);

    Tower::p_Shader spriteShader = std::make_shared<Tower::Shader>();
    spriteShader->Load("..\\..\\Assets\\Default\\Shaders\\sprite_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\sprite_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader(2, spriteShader);


    //
    // Initialize Textures
    //
    Tower::TextureManager::Instance()->LoadTexture(1, "..\\..\\Assets\\Textures\\Boxes\\box_red_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(2, "..\\..\\Assets\\Textures\\Boxes\\box_green_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(3, "..\\..\\Assets\\Textures\\Boxes\\box_blue_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(4, "..\\..\\Assets\\Textures\\Boxes\\box_8x8.png");
    Tower::TextureManager::Instance()->LoadTexture(5, "..\\..\\Assets\\Textures\\brick.png");
    Tower::TextureManager::Instance()->LoadTexture(6, "..\\..\\Assets\\Textures\\Boxes\\brown_background.png");


    BuilderTest::TestWorldOne worldOne{};
    worldOne.v_Init();

    while (!director->ShouldProgramClose())
    {
        director->StartFrame();

        if (inputManager->IsBindingPressed("exit"))
        {
            director->CloseProgram();
        }

        worldOne.v_Update();
        worldOne.v_Render();

        director->EndFrame();
    }


    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}