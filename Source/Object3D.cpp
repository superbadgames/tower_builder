#include "pch.h"
#include "BuilderTest/Entities/Object3D.hpp"

using namespace BuilderTest;

Object3D::Object3D(void) :
    _renderer(nullptr),
    _rotation()
{

}

Object3D::~Object3D(void)
{

}

void Object3D::Init(const string& modelId, const string& textureId)
{
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _renderer->AddModel(Tower::ModelManager::Instance()->Get(modelId));
    // Tower::p_Model model = std::make_shared<Tower::Model>();
    // model->SetShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    // model->LoadFromFile("..\\..\\Assets\\Default\\CubeModel\\cube.glb");
    //_renderer->AddModel(model);
    _renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture(textureId));
    _renderer->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _renderer->SetPosition(glm::vec3(0.0f, 0.0f, -30.0f));
    _renderer->ToggleRendering(true);
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

    _renderer->SetRotation(_rotation);
}

void Object3D::SetPosition(const glm::vec3& pos)
{
    _renderer->SetPosition(pos);
}