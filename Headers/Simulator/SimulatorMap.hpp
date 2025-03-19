#pragma once
#include "pch.h"
#include <Tower/framework.h>

#include "Simulator/TheZipper.hpp"
#include "Simulator/Mine.hpp"
#include "Simulator/Wall.hpp"

#include <Tower/Components/Map.hpp>
#include <Tower/Managers/TextureManager.hpp>

#include <Tower/Cameras/Camera3D.hpp>
#include <Tower/Cameras/FollowCamera.hpp>

#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <random>

namespace Simulator
{
    class SimulatorMap : public Tower::I_Map
    {
    public:
        SimulatorMap(void);

        ~SimulatorMap(void) final;

        void v_Init(void) final;

        inline void v_Release(void) final {}

        void v_Update(F32 delta) final;

        void v_Render(void) final;

    private:
        // This is all basically data...
        // If this could come from data, would I even need this file?
        static const U32 NUM_WALLS = 500;
        Wall _wallsLeft[NUM_WALLS];
        Wall _wallsRight[NUM_WALLS];
        static const U32 NUM_MINES = 500;
        Mine _mines[NUM_MINES];
        Tower::Camera3D _editorCamera;
        Tower::FollowCamera _zipperCamera;
        TheZipper _theZipper;
        F32 _editorCameraMoveSpeed;
        F32 _editorCameraSprintMultiplier;
        bool _mouseOn;
        bool _builderInControl;
    };
}