#include "pch.h"
#include "Soyokaze/Entities/Crate3D.hpp"

using namespace Soyokaze;

Crate3D::Crate3D(void) :
    _entity(),
    _rotationSpeed(15.0f),
    _angle(0.0f),
    _axis(glm::vec3(1.0f, 1.0f, 1.0f))
{
    // Default values
    // TODO:: I need a default shader, from the director, probably via a ShaderManager
    //Init("..\\..\\Assets\\Models\\cube.glb", "..\\..\\Assets\\Textures\\container.jpg");
}

Crate3D::Crate3D(Tower::p_Shader shader) :
    _entity(),
    _rotationSpeed(15.0f),
    _angle(0.0f),
    _axis(glm::vec3(1.0f, 1.0f, 1.0f))
{
    Init("..\\..\\Assets\\Models\\cube.glb", "..\\..\\Assets\\Textures\\container.jpg", shader);
}

Crate3D::Crate3D(const string& modelFilepath, const string& texture, Tower::p_Shader shader) :
    _entity(),
    _rotationSpeed(15.0f),
    _angle(0.0f),
    _axis(glm::vec3(1.0f, 1.0f, 1.0f))
{
    Init(modelFilepath, texture, shader);
}

Crate3D::~Crate3D(void)
{

}

void Crate3D::Init(const string& modelFilepath, const string& texture, Tower::p_Shader shader)
{
    _entity.AddTransform();
    _entity.AddShader(shader);
    _entity.AddModel(modelFilepath);
    _entity.AddTexture(texture);
    _entity.SetPosition(glm::vec3(0.0f, 0.0f, -2.0f));
    _entity.SetRotationAxisAndAngle(_angle, _axis);
}

void Crate3D::Init(Tower::p_Shader shader)
{
    Init("..\\..\\Assets\\Models\\cube.glb", "..\\..\\Assets\\Textures\\container.jpg", shader);
}

// void Crate3D::Draw(Tower::p_Camera camera)
// {
//     _entity.Draw(camera);
// }

void Crate3D::Update(F32 delta, F32 modifier)
{
    if (modifier == 0)
    {
        modifier = 15.0f;
    }

    modifier /= 2.0f;

    F32 newAngle = _rotationSpeed * delta;
    _angle += newAngle * modifier;

    if (_angle > 360.0f)
    {
        _angle = 0.0f;
    }

    _entity.SetRotationAngle(_angle);
}

void Crate3D::SetPosition(const glm::vec3& position)
{
    _entity.SetPosition(position);
}

void Crate3D::SetScale(const glm::vec3& scale)
{
    _entity.SetScale(scale);
}