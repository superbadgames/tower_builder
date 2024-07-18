#include "pch.h"
#include "BuilderTest/Worlds/TestWorld1.hpp"

#include <iostream>

using namespace BuilderTest;

TestWorldOne::TestWorldOne() :
    _blueBox(),
    _viewMatrix(1.0f)
{

}

TestWorldOne::~TestWorldOne()
{

}

void TestWorldOne::v_Init(Tower::p_Director director)
{
    glm::vec3 gray = { 0.2f, 0.2, 0.5f };
    director->GetWindowPointer()->SetColor(gray);

    Tower::p_Shader spriteShader = director->GetShaderManager()->GetShader(2);
    Tower::p_Texture blueBoxTexture = director->GetTextureManager()->GetTexture(1);

    _blueBox.Init(spriteShader, blueBoxTexture);
}

void TestWorldOne::v_Update(void)
{

}

void TestWorldOne::v_Render(void)
{
    _blueBox.Draw(_viewMatrix);
}