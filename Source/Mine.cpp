#include "pch.h"
#include "Simulator/Mine.hpp"

using namespace Simulator;

Mine::Mine(void) :
    _entity(nullptr),
    _rotation(),
    _moveDirection(0.0f),
    _moveSpeed(25.0f),
    _active(false),
    _moveUp(false)
{

}

Mine::~Mine(void)
{

}

void Mine::Init(const glm::vec3& position)
{
    if (_entity == nullptr)
    {
        _entity = std::make_shared<Tower::Entity>();
    }

    _entity->AddShader(Tower::ShaderManager::Instance()->GetShader("basic3d"));
    _entity->AddModel("..\\..\\Assets\\Models\\Simulator\\simulator_spike_mine_v1.glb");
    _entity->AddTexture(Tower::TextureManager::Instance()->GetTexture("mine_v1"));
    _entity->SetPosition(position);
    _entity->SetScale(glm::vec3(5.0f, 5.0f, 5.0f));
    _rotation.axis = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Mine::Draw(const glm::mat4& viewMatrix)
{
    if (_active)
    {
        glEnable(GL_DEPTH_TEST);
        _entity->Draw(viewMatrix);
    }
}

void Mine::Update(F32 delta)
{
    if (_active)
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

        glm::vec3 position = _entity->GetPosition();
        if (_moveUp)
        {
            if (position.y > _moveLimit)
            {
                _moveDirection.y = -1.0f;
            }
            else if (position.y < -_moveLimit)
            {
                _moveDirection.y = 1.0f;
            }
        }
        else
        {
            if (position.x > _moveLimit)
            {
                _moveDirection.x = -1.0f;
            }
            else if (position.x < -_moveLimit)
            {
                _moveDirection.x = 1.0f;
            }
        }

        position += _moveDirection * (_moveSpeed * delta);

        _entity->SetRotation(_rotation);
        _entity->SetPosition(position);


    }
}

void Mine::SetPosition(const glm::vec3& pos)
{
    _entity->SetPosition(pos);
}