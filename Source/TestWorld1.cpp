#include "pch.h"
#include "BuilderTest/Worlds/TestWorld1.hpp"

#include <iostream>

using namespace BuilderTest;

TestWorldOne::TestWorldOne() :
    _background(),
    _redBox(),
    _greenBox(),
    _blueBox(),
    _camera2d(nullptr),
    _cameraMoveSpeed(3.0f)
{

}

TestWorldOne::~TestWorldOne()
{

}

void TestWorldOne::v_Init(F32 screenWidth, F32 screenHeight, F32 fov, F32 viewDistance)
{
    Tower::Director::Instance()->SetWindowBackgroundColor(glm::vec3(0.2f, 0.2, 0.2f));

    _camera2d = std::make_shared<Tower::Camera2D>();
    _camera2d->v_Init(screenWidth, screenHeight, fov, viewDistance);
    // This is awkward and terrible, but only for now.
    // I need to create an object to hold and move the camera for the 2d map,
    // but this is a very low priority for now
    _camera = _camera2d;

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

void TestWorldOne::v_Update(F32 delta)
{
    // TODO:
    // Refactor all these controls into various other objects that actually control this logic
    // For instance, make a Camera2D, not in the engine maybe, but here to be re-used in later games/projects
    // and put these controls in that object
    // Maybe later, consider putting this in LUA, or just leaving here
    if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_up"))
    {
        _camera2d->Move(glm::vec2(0.0f, 1.0f) * _cameraMoveSpeed);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_down"))
    {
        _camera2d->Move(glm::vec2(0.0f, -1.0f) * _cameraMoveSpeed);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_right"))
    {
        _camera2d->Move(glm::vec2(1.0f, 0.0f) * _cameraMoveSpeed);
    }
    else if (Tower::InputManager::Instance()->IsBindingPressedOrHeld("camera_move_left"))
    {
        _camera2d->Move(glm::vec2(-1.0f, 0.0f) * _cameraMoveSpeed);
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

    _redBox.Update(delta);
    _greenBox.Update(delta);
    _blueBox.Update(delta);
}
