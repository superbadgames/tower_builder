#include "pch.h"
#include "Simulator/TheZipper.hpp"

using namespace Simulator;

TheZipper::TheZipper(void) :
    _entity(nullptr),
    _rotation()
{

}

TheZipper::~TheZipper(void)
{

}

void TheZipper::Init(const glm::vec3& position)
{
    if (_entity == nullptr)
    {
        _entity = std::make_shared<Tower::Entity>();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader(3));
    _entity->AddModel("..\\..\\Assets\\Models\\Simulator\\zipper_v1.glb");
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture(8));
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, -30.0f));
}

void TheZipper::Draw(const glm::mat4& viewMatrix)
{
    glEnable(GL_DEPTH_TEST);
    glm::mat4 combinedViewMatrix = Tower::Director::Instance()->GetPerspectiveMatrix() * viewMatrix;
    _entity->Draw(combinedViewMatrix);
}

void TheZipper::Update(F32 delta)
{

}

void TheZipper::SetPosition(const glm::vec3& pos)
{
    _entity->SetPosition(pos);
}