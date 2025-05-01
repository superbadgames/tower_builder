/*

The Editor

*/
#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Entity.hpp>

namespace TowerBuilder
{
    class Editor
    {
    public:
        Editor(void);

        ~Editor(void);

        void Init(void);

    private:
        Tower::p_Entity _entity;
    };
}