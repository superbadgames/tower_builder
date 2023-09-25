// #pragma once

// #include "pch.h"
// #include "Tower/framework.h"
// #include "Tower/Entity.hpp"
// #include <glm/mat4x4.hpp>
// #include <glm/vec3.hpp>
// #include <glm/gtc/quaternion.hpp>
// #include <glm/gtc/matrix_transform.hpp>

// namespace Tower
// {
//     class Camera
//     {
//     public:
//         Camera(void);

//         // TODO: implement copy
//         //Camera(const Camera& copy);
//         // Camera& operator=(const Camera& right);

//         ~Camera(void);

//         void Init(p_Entity target, const glm::vec3& offset);

//         void Update(F32 delta, F32 yaw, F32 pitch);

//         inline const glm::mat4& GetViewMatrix(void) const
//         {
//             return _viewMatrix;
//         }


//     private:
//         void _UpdateViewMatrix(void);

//         glm::mat4 _viewMatrix;
//         glm::vec3 _targetOffset;
//         glm::vec3 _worldUp;
//         p_Entity _target;
//         F32 _yaw;
//         F32 _pitch;
//         F32 _pitchClampAmount;
//         bool _clampPitch;

//         // TODO: figure out how zoom would work
//         //F32 _zoom;
//     };
//     typedef shared_ptr<Camera> p_Camera;
// }