#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <cassert>
#include <queue>
#include <array>

namespace Tower
{
    class EntityManager
    {
    public:
        EntityManager(void);

        ~EntityManager(void);

        Entity CreateEntity(void);

        void DestroyEntity(Entity entity);

        void SetSignature(Entity entity, Signature signature);

        Signature GetSignature(Entity entity);

    private:
        // TODO: consider writing your own queue
        std::queue<Entity> _entities;
        std::array<Signature, MAX_ENTITIES> _signatures;
        U32 _activeEntities;
    };
    typedef std::shared_ptr<EntityManager> p_EntityManager;
};