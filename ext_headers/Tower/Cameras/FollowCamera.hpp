#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/InputManager.hpp"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class FollowCamera
    {
    public:
        FollowCamera(void);

        ~FollowCamera(void);

        void Init(const glm::mat4& projectionMatrix);

        void Update(const glm::vec3& targetPos, const glm::vec3& targetUp, const glm::vec3& targetDirection);

        inline void SetOffset(const glm::vec2& offset) { _cameraOffset = offset; }

        inline const glm::mat4& GetViewMatrix(void) const { return _viewMatrix; }

    private:
        glm::mat4 _projectionMatrix;
        glm::mat4 _viewMatrix;
        glm::vec3 _eye;
        glm::vec3 _cameraForward;
        glm::vec3 _cameraLeft;
        glm::vec3 _cameraUp;
        glm::vec2 _cameraOffset;
        F32 _followDistance;
    };
}