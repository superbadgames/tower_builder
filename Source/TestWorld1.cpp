#include "pch.h"
#include "BuilderTest/Worlds/TestWorld1.hpp"

#include <iostream>

using namespace BuilderTest;

TestWorldOne::TestWorldOne() :
    _background(),
    _redBox(),
    _greenBox(),
    _blueBox(),
    _glyph_S(),
    _font(nullptr),
    _glyphColor(1.0f, 1.0f, 1.0f),
    _cameraMoveSpeed(3.0f)
{

}

TestWorldOne::~TestWorldOne()
{

}

void TestWorldOne::v_Init(void)
{
    glm::vec3 gray = { 0.2f, 0.2, 0.2f };
    Tower::Director::Instance()->GetWindowPointer()->SetColor(gray);

    Tower::p_Shader spriteShader = Tower::ShaderManager::Instance()->GetShader(2);
    Tower::p_Texture redTexture = Tower::TextureManager::Instance()->GetTexture(1);
    Tower::p_Texture greenTexture = Tower::TextureManager::Instance()->GetTexture(2);
    Tower::p_Texture blueTexture = Tower::TextureManager::Instance()->GetTexture(3);

    _background.Init(spriteShader, Tower::TextureManager::Instance()->GetTexture(6));
    _background.SetScale(glm::vec2(500, 500));

    _redBox.Init(spriteShader, redTexture);
    _redBox.SetPosition(glm::vec2(400.0f, -400.0f));
    _greenBox.Init(spriteShader, greenTexture);
    _greenBox.SetPosition(glm::vec2(-400.0f, -400.0f));
    _blueBox.Init(spriteShader, blueTexture);
    _blueBox.SetActive(true);

    _font = std::make_shared<Tower::Font>();
    _font->Load("H:\\SuperBadGames\\Tower_Builder\\Assets\\Default\\Fonts\\PressStart2P-Regular.ttf", 48);


    _glyph_S.Init(_font->GetCharacterData('S'));
    _glyph_S.SetScale(glm::vec2(100.0f, 100.0f));
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

    Tower::p_Shader glyphShader = Tower::ShaderManager::Instance()->GetShader(1);
    glyphShader->SetUniform("projection", Tower::Director::Instance()->GetCamera2D()->GetProjectionMatrix());


    _glyph_S.Draw(glyphShader, _glyphColor);
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