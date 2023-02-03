#include "pch.h"
#include "framework.hpp"
#include "Soyokaze/Worlds/SpinningCrates.hpp"
#include <Tower/Components/World.hpp>
#include <Tower/Managers/Director.hpp>
#include <Tower/Rendering/Shader.hpp>
#include <Tower/Rendering/Texture.hpp>
#include <Tower/Managers/ShaderManager.hpp>

#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;
    const U32 BASIC_SHADER_ID = 1;
    const U32 CRATE_TEXTURE_ID = 1;

    Tower::p_Director director = Tower::Director::Instance();

    if (!director->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    //
    // Initialize shaders
    //
    Tower::p_Shader basicShader = std::make_shared<Tower::Shader>();
    basicShader->Load("..\\..\\Assets\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Shaders\\basic_fragment.glsl");
    director->GetShaderManager()->RegisterShader(BASIC_SHADER_ID, basicShader);

    //
    // Initialize Textures
    //
    director->GetTextureManager()->LoadTexture(CRATE_TEXTURE_ID, "..\\..\\Assets\\Textures\\container.jpg");

    Tower::p_World spinningCratesWorld = make_shared<Soyokaze::SpinningCrates>();
    spinningCratesWorld->v_Init(director);

    while (!director->ShouldProgramClose())
    {
        spinningCratesWorld->v_Update();
        spinningCratesWorld->v_Render();
    }

    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}