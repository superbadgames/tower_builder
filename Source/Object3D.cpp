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

void Object3D::Init(const string& modelId, const string& textureId)
{
    if (_entity == nullptr)
    {
        _entity = Tower::EntityManager::Instance()->GetNext();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _entity->AddModel(Tower::ModelManager::Instance()->Get(modelId));
    // Tower::p_Model model = std::make_shared<Tower::Model>();
    // model->SetShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    // model->LoadFromFile("..\\..\\Assets\\Default\\CubeModel\\cube.glb");
    //_entity->AddModel(model);
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture(textureId));
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _entity->SetPosition(glm::vec3(0.0f, 0.0f, -30.0f));
    _entity->ToggleRendering(true);
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