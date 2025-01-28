#include "pch.h"
#include "BuilderTest/Entities/Object3D.hpp"

using namespace BuilderTest;

Object3D::Object3D(void) :
    _entity(nullptr),
    _rotation()
{

}

Object3D::~Object3D(void)
{

}

void Object3D::Init(const string& filepath, U32 textureId)
{
    if (_entity == nullptr)
    {
        _entity = std::make_shared<Tower::Entity>();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader(3));
    _entity->AddModel(filepath);
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture(textureId));
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, -30.0f));
}

void Object3D::Draw(const glm::mat4& viewMatrix)
{
    glEnable(GL_DEPTH_TEST);
    _entity->Draw(viewMatrix);
}

void Object3D::Update(F32 delta)
{
    _rotation.angle -= delta * 10.0f;

    if (_rotation.angle <= -360.0f)
    {
        _rotation.angle = 360.0f;
    }
    else if (_rotation.angle >= 360.0f)
    {
        _rotation.angle = -360.0f;
    }

    _entity->SetRotation(_rotation);
}

void Object3D::SetPosition(const glm::vec3& pos)
{
    _entity->SetPosition(pos);
}