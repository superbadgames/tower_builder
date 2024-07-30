#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Transform.hpp"
// #include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Model.hpp"
#include "Tower/Rendering/Mesh.hpp"
#include "Tower/Rendering/Sprite.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Rendering/Color.hpp"

namespace Tower
{
    class Entity
    {
    public:
        Entity(void);

        ~Entity(void);

        void Draw(const glm::mat4 &viewMatrix) const;

        void Update(F32 delta);

        void AddTransform(void);

        void AddModel(void);

        void AddModel(const string &filePath);

        void AddSprite(p_Shader shader, p_Texture texture);

        void AddShader(void);

        void AddShader(p_Shader shader);

        void AddTexture(const string &filepath);

        inline void AddTexture(p_Texture texture) { _model->SetTexture(texture); }

        inline const Color &GetColor(void) const { return _color; }

        void SetColor(const Color &color);

    private:
        p_Transform _transform;
        p_Model _model;
        p_Sprite _sprite;
        p_Shader _shader;
        Color _color;
    };
    typedef shared_ptr<Entity> p_Entity;
}