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

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    //_entity->AddModel("..\\..\\Assets\\Default\\CubeModel\\cube.glb");
    //_entity->AddTexture(Tower::TextureManager::Instance()->GetTexture(7));
    _entity->AddCubeModel(Tower::TextureManager::Instance()->GetTexture("brick"));
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, -30.0f));
    _rotation.angle = -55.0f;
    _rotation.axis = glm::vec3(1.0f, 1.0f, 0.0f);
    _entity->SetRotation(_rotation);
}

void Box3D::Draw(const glm::mat4& viewMatrix)
{
    // the winding order for the cube is wrong, so for this draw I'll disable face culling
    glDisable(GL_CULL_FACE);
    _entity->Draw(viewMatrix);
    glEnable(GL_CULL_FACE);
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