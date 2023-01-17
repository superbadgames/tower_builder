#include "pch.h"
#include "Lateralus/Crate3D.hpp"

using namespace Lateralus;

Crate3D::Crate3D(void):
    _towerObject(),
    _rotationSpeed(15.0f),
    _angle(0.0f),
    _axis(glm::vec3(1.0f, 1.0f, 1.0f))
{
    // Default values
    // TODO:: I need a default shader, from the director, probably via a ShaderManager
    //Init("..\\..\\Assets\\Models\\cube.glb", "..\\..\\Assets\\Textures\\container.jpg");
}

Crate3D::Crate3D(Tower::p_Shader shader):
    _towerObject(),
    _rotationSpeed(15.0f),
    _angle(0.0f),
    _axis(glm::vec3(1.0f, 1.0f, 1.0f))
{
    Init("..\\..\\Assets\\Models\\cube.glb", "..\\..\\Assets\\Textures\\container.jpg", shader);
}

Crate3D::Crate3D(const string& modelFilepath, const string& texture, Tower::p_Shader shader):
    _towerObject(),
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
    _towerObject.AddTransform();
    _towerObject.AddShader(shader);
    _towerObject.AddModel(modelFilepath);
    _towerObject.AddTexture(texture);
    _towerObject.SetPosition(glm::vec3(0.0f, 0.0f, -2.0f));
    _towerObject.SetRotationAxisAndAngle(_angle, _axis);
}

void Crate3D::Init(Tower::p_Shader shader)
{
    Init("..\\..\\Assets\\Models\\cube.glb", "..\\..\\Assets\\Textures\\container.jpg", shader);
}

void Crate3D::Draw(void)
{
    _towerObject.Draw();
}

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

    _towerObject.SetRotationAngle(_angle);
}

void Crate3D::SetPosition(const glm::vec3& position)
{
    _towerObject.SetPosition(position);
}

void Crate3D::SetScale(const glm::vec3& scale)
{
    _towerObject.SetScale(scale);
}