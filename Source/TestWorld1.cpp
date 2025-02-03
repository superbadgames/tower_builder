#include "pch.h"
#include "BuilderTest/Worlds/TestWorld1.hpp"

#include <iostream>

using namespace BuilderTest;

TestWorldOne::TestWorldOne() :
    _background(),
    _redBox(),
    _greenBox(),
    _blueBox(),
    _cameraMoveSpeed(3.0f)
{

}

TestWorldOne::~TestWorldOne()
{

}

void TestWorldOne::v_Init(void)
{
    Tower::Director::Instance()->GetWindowPointer()->SetColor(glm::vec3(0.2f, 0.2, 0.2f));

    Tower::p_Shader spriteShader = Tower::ShaderManager::Instance()->GetShader("sprite");
    Tower::p_Texture redTexture = Tower::TextureManager::Instance()->GetTexture("redbox");
    Tower::p_Texture greenTexture = Tower::TextureManager::Instance()->GetTexture("greenbox");
    Tower::p_Texture blueTexture = Tower::TextureManager::Instance()->GetTexture("bluebox");

    _background.Init(spriteShader, Tower::TextureManager::Instance()->GetTexture("brown_background"));
    _background.SetScale(glm::vec2(500, 500));

    _redBox.Init(spriteShader, redTexture);
    _redBox.SetPosition(glm::vec2(400.0f, -400.0f));
    _greenBox.Init(spriteShader, greenTexture);
    _greenBox.SetPosition(glm::vec2(-400.0f, -400.0f));
    _blueBox.Init(spriteShader, blueTexture);
    _blueBox.SetActive(true);
}

void TestWorldOne::v_Update(void)
{
    F32 delta = Tower::Director::Instance()->GetDeltaTime();
    _CheckInput();
    _redBox.Update(delta);
    _greenBox.Update(delta);
    _blueBox.Update(delta);
}

void TestWorldOne::v_Render(void)
{
    glm::mat4 viewMatrix = Tower::Director::Instance()->GetCamera2D()->GetViewMatrix();

    _background.Draw(viewMatrix);

    _redBox.Draw(viewMatrix);
    _greenBox.Draw(viewMatrix);
    _blueBox.Draw(viewMatrix);
}

void TestWorldOne::_CheckInput(void)
{

    if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_up"))
    {
        Tower::Director::Instance()->GetCamera2D()->Move(glm::vec2(0.0f, 1.0f) * _cameraMoveSpeed);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_down"))
    {
        Tower::Director::Instance()->GetCamera2D()->Move(glm::vec2(0.0f, -1.0f) * _cameraMoveSpeed);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_right"))
    {
        Tower::Director::Instance()->GetCamera2D()->Move(glm::vec2(1.0f, 0.0f) * _cameraMoveSpeed);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_left"))
    {
        Tower::Director::Instance()->GetCamera2D()->Move(glm::vec2(-1.0f, 0.0f) * _cameraMoveSpeed);
    }

    if (Tower::InputManager::Instance()->IsBindingPressed("red_box"))
    {
        _redBox.SetActive(true);
        _greenBox.SetActive(false);
        _blueBox.SetActive(false);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressed("green_box"))
    {
        _redBox.SetActive(false);
        _greenBox.SetActive(true);
        _blueBox.SetActive(false);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressed("blue_box"))
    {
        _redBox.SetActive(false);
        _greenBox.SetActive(false);
        _blueBox.SetActive(true);
    }
}