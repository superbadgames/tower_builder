#include "pch.h"
#include "BuilderTest/Entities/Box3D.hpp"

#include <Tower/Managers/TextureManager.hpp>

using namespace BuilderTest;

Box3D::Box3D(void) :
    _renderer(nullptr),
    _rotation()
{

}

Box3D::~Box3D(void)
{

}

void Box3D::Init(void)
{
    if (_renderer == nullptr)
    {
        _renderer = Tower::RenderingManager::Instance()->GetNext();
    }

    _renderer->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    // There are two ways in the Tower Engine to create a cube. You can use a texture,
    // created using the default cube from blender. This works fine.
    // The "Cube Model" is made by hand, during the early stages of rendering development.
    /// It's here more as a test than anything else.
    //_renderer->AddModel("..\\..\\Assets\\Default\\CubeModel\\cube.glb");
    //_renderer->AddTexture(Tower::TextureManager::Instance()->GetTexture(7));
    _renderer->AddCubeModel(Tower::TextureManager::Instance()->GetTexture("brick"));
    _renderer->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
    _renderer->SetPosition(glm::vec3(0.0f, 0.0f, -30.0f));
    _rotation.angle = -55.0f;
    _rotation.axis = glm::vec3(1.0f, 1.0f, 0.0f);
    _renderer->SetRotation(_rotation);
    _renderer->ToggleRendering(true);
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

    _renderer->SetRotation(_rotation);
}

void Box3D::SetPosition(const glm::vec3& pos)
{
    _renderer->SetPosition(pos);
}