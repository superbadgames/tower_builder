#include "pch.h"
#include "BuilderTest/Entities/Box3D.hpp"

#include <Tower/Managers/TextureManager.hpp>

using namespace BuilderTest;

Box3D::Box3D(void) :
    _entity(nullptr),
    _rotation()
{

}

Box3D::~Box3D(void)
{

}

void Box3D::Init(void)
{
    if (_entity == nullptr)
    {
        _entity = std::make_shared<Tower::Entity>();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader(3));
    //_entity->AddModel("..\\..\\Assets\\Default\\CubeModel\\cube.glb");
    //_entity->AddTexture(Tower::TextureManager::Instance()->GetTexture(7));
    _entity->AddCubeModel(Tower::TextureManager::Instance()->GetTexture(5));
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, -30.0f));
    _rotation.angle = -55.0f;
    _rotation.axis = glm::vec3(1.0f, 1.0f, 0.0f);
    _entity->SetRotation(_rotation);
}

void Box3D::Draw(const glm::mat4& viewMatrix)
{
    //glDisable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH_TEST);
    //_entity->GetShader()->SetUniform("projection", Tower::Director::Instance()->GetPerspectiveMatrix());
    //_entity->GetShader()->SetUniform("projection", Tower::Director::Instance()->GetOrthographicMatrix());
    glm::mat4 combinedViewMatrix = Tower::Director::Instance()->GetPerspectiveMatrix() * viewMatrix;
    _entity->Draw(combinedViewMatrix);
}

void Box3D::Update(F32 delta)
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

void Box3D::SetPosition(const glm::vec3& pos)
{
    _entity->SetPosition(pos);
}