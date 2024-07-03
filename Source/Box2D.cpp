#include "pch.h"
#include "BuilderTest/Entities/Box2D.hpp"

#include <iostream>

using namespace BuilderTest;

Box2D::Box2D(void)
    :
    _entity(nullptr)
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

    _entity->AddTransform();
    _entity->AddSprite(shader, texture);
}

void Box2D::Draw(const glm::mat4& viewMatrix)
{
    std::cout << "draw called\n";
    _entity->Draw(viewMatrix);
}