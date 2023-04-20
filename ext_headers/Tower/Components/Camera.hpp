#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Camera
    {
    public:
        Camera(void);

        Camera(const glm::vec3& position,
            const glm::vec3& front,
            const glm::vec3& worldUp,
            F32 yaw,
            F32 pitch,
            F32 speed,
            F32 turnSpeed,
            F32 zoom);

        ~Camera(void);

        void Init(F32 fov = 45.0f, S32 width = 800, S32 height = 600, F32 near = 0.1f, F32 far = 100.0f);

        // TODO: Should delta time be part of this? Or should the camera just have its own clock? hmmm...
        // TODO: Should this live in the camera?
        //void KeyControl(const bool* keys, F64 deltaTime);

        // This is not the same as SET position
        void UpdatePosition(const glm::vec3& direction, F64 deltaTime);

        void SetPosition(const glm::vec3& position);

        void UpdateYaAndPitch(F32 yaw, F32 pitch);

        void CalculateViewMatrix(void);

        inline glm::mat4 GetProjectionMatrix(void) const { return _projection; }

        inline void SetViewMatrix(const glm::mat4& view) { _view = view; }

        inline const glm::mat4& GetViewMatrix(void) const { return _view; }

        inline void SetMovementSpeed(F32 speed) { _moveSpeed = speed; }

        void MoveForward(F32 delta);

        void MoveBack(F32 delta);

        void MoveRight(F32 delta);

        void MoveLeft(F32 delta);

        void Move(const glm::vec3& direction, F32 delta);

        // Update yaw by offset, apply turn speed
        void UpdateYaw(F32 offset);

        // Update pitch by offset, apply turn speed
        void UpdatePitch(F32 offset, bool clamp = true);

        inline void AllowMove(void) { _canMove = true; }

        inline void StopMove(void) { _canMove = false; }

        inline bool GetCanMove(void) { return _canMove; }



    private:
        void _UpdateVectors(void);

        glm::mat4 _view;
        glm::mat4 _projection;
        glm::vec3 _position;
        glm::vec3 _front;
        glm::vec3 _cameraUp;
        glm::vec3 _right;
        glm::vec3 _worldUp;
        bool _canMove;

        F32 _yaw;
        F32 _pitch;
        F32 _moveSpeed;
        F32 _turnSpeed;
        F32 _zoom;

        F32 _lastYaw;
        F32 _lastPitch;
    };
    typedef shared_ptr<Camera> p_Camera;
}