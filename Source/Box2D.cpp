#include "pch.h"
#include "BuilderTest/Entities/Box2D.hpp"

#include <iostream>

using namespace BuilderTest;

Box2D::Box2D(void)
    :
    _entity(nullptr),
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
    //_entity->GetModel()->EnableWireframeMode();
}

void Box2D::Draw(const glm::mat4& viewMatrix)
{
    _entity->Draw(viewMatrix);
}

void Box2D::Update(void)
{
    _counter += 0.03f;

    if (_counter <= _timer)
    {
        
    }

}