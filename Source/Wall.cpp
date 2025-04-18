#include "pch.h"
#include "Simulator/Wall.hpp"

using namespace Simulator;

Wall::Wall(void) :
    _entity(nullptr),
    _rotation(),
    _active(false)
{

}

Wall::~Wall(void)
{

}

void Wall::Init(const glm::vec3& position)
{
    if (_entity == nullptr)
    {
        _entity = std::make_shared<Tower::Entity>();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _entity->AddModel("..\\..\\Assets\\Models\\Simulator\\simulator_wall_v1.glb");
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture("wall_v1"));
    _entity->SetPosition(position);
    _entity->SetScale(glm::vec3(10.0f, 10.0f, 10.0f));
}

void Wall::Draw(const glm::mat4& viewMatrix)
{
    if (_active)
    {
        glEnable(GL_DEPTH_TEST);
        _entity->Draw(viewMatrix);
    }
}

void Wall::Update(F32 delta)
{

}
