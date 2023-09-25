#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Transform.hpp"
//#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Model.hpp"
#include "Tower/Rendering/Mesh.hpp"
#include "Tower/Rendering/Shader.hpp"

namespace Tower
{
    class IEntity
    {
    public:
        IEntity(void);

        ~IEntity(void);

        // TODO: Move this code into the RenderingSystem
        //void Draw(const glm::mat4& viewMatrix) const;

        virtual void v_Update(F32 delta) = 0;

        void InitModel(const string& filePath);

        void InitSprite(p_Shader shader, p_Texture texture);

        void SetShader(p_Shader shader);

        void InitTexture(const string& filepath);

        inline void AddTexture(p_Texture texture)
        {
            _model.SetTexture(texture);
        }

        glm::vec3 GetPosition(void) const;

        void SetPostion(const glm::vec3& position);

        //
        //TODO:: Look at all of this and decide what is worth keeping. I think there is a better way to do all of this.
        //
        const glm::vec3& GetRotationAxis(void) const;

        F32 GetRotationAngle(void) const;

        void SetRotationAxisAndAngle(F32 angle, const glm::vec3& axis);

        void SetRotationAngle(F32 angle);

        void SetRotationAxis(const glm::vec3& axis);

        const glm::vec3& GetScale(void) const;

        void SetScale(const glm::vec3& scale);

        void SetPosition(const glm::vec3& position);

        void SetColor(const glm::vec4& color);

        const glm::mat4& GetTransform(void);

        const Model& GetModel(void) const;

        inline const glm::mat4& GetModelMatrix(void)
        {
            return _transform.GetTransform();
        }

        inline p_Shader GetShader(void) const
        {
            return _shader;
        }

        inline const glm::vec4& GetColor(void) const
        {
            return _transform.color;
        }


    private:
        Transform _transform;
        Model _model;
        p_Shader _shader;
    };
    typedef shared_ptr<IEntity> p_Entity;
}