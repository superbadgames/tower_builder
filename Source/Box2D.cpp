#include "pch.h"
#include "BuilderTest/Entities/Box2D.hpp"

#include <iostream>

using namespace BuilderTest;

Box2D::Box2D(void)
    : _entity(nullptr),
    _counter(0.0f),
    _timer(5.0f),
    _currentTexture(1)
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
    _entity->SetScale(glm::vec3(0.25f, 0.25f, 0.25f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    _entity->SetRotation(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Box2D::Draw(const glm::mat4& viewMatrix)
{
    _entity->Draw(viewMatrix);
}

void Box2D::Update(F32 delta)
{
    _counter += 0.03f;

    if (_counter <= _timer)
    {
    }
}

void Box2D::SetColor(const Tower::Color& color)
{
    _entity->SetColor(color);
}