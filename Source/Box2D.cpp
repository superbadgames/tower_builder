#include "pch.h"
#include "BuilderTest/Entities/Box2D.hpp"

#include <iostream>

using namespace BuilderTest;

Box2D::Box2D(void) :
    _entity(nullptr),
    _active(false),
    _counter(0.0f),
    _timer(5.0f),
    _currentTexture(1),
    _moveSpeed(6.0f)
{
}

Box2D::~Box2D(void)
{
}

void Box2D::Init(Tower::p_Shader shader, Tower::p_Texture texture)
{
    if (_entity == nullptr)
    {
        _entity = std::make_shared<Tower::Entity>();
    }

    _entity->AddSprite(shader, texture);
    _entity->SetScale(glm::vec3(50.0f, 50.0f, 0.0f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    _entity->SetRotation(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Box2D::Draw(const glm::mat4& viewMatrix)
{
    _entity->Draw(viewMatrix);
}

void Box2D::Update(void)
{
    glm::vec3 position = _entity->GetPosition();
    if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_up"))
    {
        position.y += _moveSpeed;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_down"))
    {
        position.y -= _moveSpeed;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_right"))
    {
        position.x += _moveSpeed;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressedOrHeld("move_left"))
    {
        position.x -= _moveSpeed;
    }
    else if (_active && Tower::InputManager::Instance()->IsBindingPressed("reset_position"))
    {
        position = glm::vec3(0.0f);
    }

    _entity->SetPosition(position);
}

void Box2D::SetColor(const Tower::Color& color)
{
    _entity->SetColor(color);
}

void Box2D::SetPosition(const glm::vec2& pos)
{
    _entity->SetPosition(glm::vec3(pos, 0.0f));
}


void Box2D::SetActive(bool state)
{
    _active = state;
}