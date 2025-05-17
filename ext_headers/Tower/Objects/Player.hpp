#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Renderer.hpp"
#include "Tower/Math/Transform.hpp"

#include <glm/gtx/transform.hpp>

namespace Tower
{
    class Player;
    typedef shared_ptr<Player> p_Player;

    class Player
    {
    public:
        Player(void);

        Player(const Player& copy);

        Player& operator=(const Player& copy);

        virtual ~Player(void);

        virtual void v_Init(void) = 0;

        virtual void v_Activate(void) = 0;

        virtual void v_Deactivate(void) = 0;

        virtual void v_Update(F32 delta) = 0;

        void Render(void);

        inline bool IsActive(void) const { return _active; }

        inline bool IsRendering(void) const { return _render; }

        inline p_Renderer GetRenderer(void) const { return _renderer; }

        inline const glm::vec3& GetForward(void) const { return _forward; }

        inline p_Transform GetTransform(void) const { return _transform; }

        const glm::vec3& GetPosition(void) const;

        void SetPosition(const glm::vec3& position);

        const glm::vec3& GetScale(void) const;

        void SetScale(const glm::vec3& scale);

        const AxisAngle& GetRotation(void) const;

        void SetRotation(const AxisAngle& rotation);

        void SetRotation(F32 angle, const glm::vec3& axis);

    protected:
        bool _active;
        bool _render;
        // Replace later with a call to get the velocity from the rigidbody
        glm::vec3 _forward;
        p_Renderer _renderer;
        p_Transform _transform;

        void _DefaultInit(void);

    };
}