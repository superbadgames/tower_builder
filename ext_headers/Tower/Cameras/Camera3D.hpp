#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/InputManager.hpp"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Camera3D
    {
    public:
        Camera3D(void);

        ~Camera3D(void);

        void Init(const glm::mat4& projectionMatrix);

        void Update(F32 delta);

        inline const glm::mat4& GetViewMatrix(void) const { return _viewMatrix; }

        void SetPosition(const glm::vec3& pos);

        inline const glm::vec3& GetPosition(void) const { return _position; }

        void MoveForward(F32 speed);

        void MoveBack(F32 speed);

        void MoveRight(F32 speed);

        void MoveLeft(F32 speed);

        void MoveUp(F32 speed);

        void MoveDown(F32 speed);

    private:
        glm::mat4 _projectionMatrix;
        glm::mat4 _viewMatrix;
        glm::vec3 _position;
        glm::vec3 _target;
        glm::vec3 _facingDirection;
        glm::vec3 _worldUp;
        glm::vec3 _cameraUp;
        glm::vec3 _cameraRight;
        const F32 _radius = 10.0f;
        F32 _yaw;
        F32 _pitch;
        F32 _roll;
    };
}