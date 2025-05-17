#pragma once

#ifdef BUILDER_EXPORTS
#define BUILDER_API __declspec(dllexport)
#else
#define BUILDER_API __declspec(dllimport)
#endif

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Objects/Player.hpp>

namespace Builder
{
    class BUILDER_API Editor;
    typedef BUILDER_API shared_ptr<Editor> p_Editor;

    class BUILDER_API Editor : public Tower::Player
    {
    public:
        Editor(void);

        Editor(const Editor& copy);

        Editor& operator=(const Editor& copy);

        ~Editor(void) final;

        void v_Init(void) final;

        void v_Activate(void) final;

        void v_Deactivate(void) final;

        void v_Update(F32 delta) final;
    private:
    };
}