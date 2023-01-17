#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/VertexAttribute.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Rendering/Texture.hpp"
#include "glm/vec4.hpp"
#include <vector>

namespace Tower
{
    class Sprite
    {
    public:
        Sprite(void);

        ~Sprite(void);

        void Init(p_Shader shader);

        void Draw(p_Shader shader);

        void Use(void);

        void StopUse(void);

        void EnableWireframeMode(void);

        void DisableWireframeMode(void);

        inline void SetTexture(p_Texture texture) { _texture = texture; }

    private:
        GLuint _vao;        // Vertex Array Object
        GLuint _ebo;        // Element Buffer Object
        std::vector<F32> _vertexPositions;
        VertexAttribute _positionBuffer;
        std::vector<U32> _indices;
        std::vector<F32> _vertexUvs;
        VertexAttribute _uvBuffer;
        p_Texture _texture;
    };
    typedef shared_ptr<Sprite> p_Sprite;
}