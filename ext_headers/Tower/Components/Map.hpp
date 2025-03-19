#pragma once

#include "pch.h"
#include "Tower/framework.h"


namespace Tower
{
    class I_Map
    {
    public:
        I_Map(void);

        virtual ~I_Map(void);

        // TODO: After a text parser is build
        // After Entity Serialization is working
        // This Init function can take a filepath to load
        //inline virtual void v_Init(const string& filepath) {}
        inline virtual void v_Init(void) = 0;

        inline virtual void v_Release(void) = 0;

        inline virtual void v_Update(F32 delta) = 0;

        inline virtual void v_Render(void) = 0;

    };
    typedef shared_ptr<I_Map> p_Map;
}