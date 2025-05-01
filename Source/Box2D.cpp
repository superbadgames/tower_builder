#include "pch.h"
#include "BuilderTest/Entities/Box2D.hpp"

#include <iostream>

using namespace BuilderTest;

Box2D::Box2D(void) :
    _renderer(nullptr),
    _active(false),
    _counter(0.0f),
    _timer(5.0f),
    _currentTexture(1),
    _moveSpeed(600.0f)
{
}

Box2D::~Box2D(void)
{
}

void Box2D::Init(Tower::p_Shader shader, Tower::p_Texture texture)
{
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddSprite(shader, texture);
    _renderer->SetScale(glm::vec3(50.0f, 50.0f, 0.0f));
    _renderer->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    _renderer->SetRotation(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Box2D::Update(F32 delta)
{
    glm::vec3 position = _renderer->GetPosition();

    if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_up"))
    {
        position.y += _moveSpeed * delta;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_down"))
    {
        position.y -= _moveSpeed * delta;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_right"))
    {
        position.x += _moveSpeed * delta;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_left"))
    {
        position.x -= _moveSpeed * delta;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressed("reset_position"))
    {
        position = glm::vec3(0.0f);
    }

    _renderer->SetPosition(position);
}

void Box2D::SetColor(const Tower::Color& color)
{
    _renderer->SetColor(color);
}

void Box2D::SetPosition(const glm::vec2& pos)
{
    _renderer->SetPosition(glm::vec3(pos, 0.0f));
}

void Box2D::SetZPosition(F32 zPos)
{
    glm::vec3 currentPos = _renderer->GetPosition();
    currentPos.z = zPos;
    _renderer->SetPosition(currentPos);
}

void Box2D::SetScale(const glm::vec2& scale)
{
    _renderer->SetScale(glm::vec3(scale, 0.0f));
}


void Box2D::SetActive(bool state)
{
    _active = state;
}