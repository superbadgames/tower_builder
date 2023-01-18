#pragma once
#include "pch.h"
#include "Tower/framework.h"


#include <array>
#include <unordered_map>
#include <cassert>
#include <cstddef>

namespace Tower
{
    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void v_EntityDestroyed(EntityID entityID) = 0;
    };
    typedef shared_ptr<IComponentArray> p_IComponentArray;

    template<typename T>
    class ComponentArray: public IComponentArray
    {
    public:
        ComponentArray(void)
            :
            _componentArray{},
            _entityIDToIndex{},
            _indexToEntityID{},
            _nextIndex(0)
        {

        }

        ~ComponentArray(void)
        {

        }

        void InsertData(EntityID entityID, T component)
        {
            assert(_entityIDToIndex.find(entityID) == _entityIDToIndex.end() && "ComponentArray failed InsertData! Duplicate call made!");

            size_t index = _nextIndex;
            _entityIDToIndex[entityID] = index;
            _indexToEntityID[index] = entityID;
            _componentArray[index] = component;
            ++_nextIndex;
        }

        void RemoveData(EntityID entityID)
        {
            assert(_entityIDToIndex.find(entityID) != _entityIDToIndex.end() && "ComponentArray failed RemoveData! No such EntityID!");

            size_t indexRemoved = _entityIDToIndex[entityID];
            size_t indexLastElement = _nextIndex - 1;
            _componentArray[indexRemoved] = _componentArray[indexLastElement];

            EntityID entityIDLastElement = _indexToEntityID[indexLastElement];
            _entityIDToIndex[entityIDLastElement] = indexRemoved;
            _indexToEntityID[indexRemoved] = entityIDLastElement;

            --_nextIndex;
        }


        T& GetData(EntityID entityID)
        {
            assert(HasData(entityID) && "ComponentArray failed GetData! No such EntityID!");
            return _componentArray[entityID];
        }

        bool HasData(EntityID entityID)
        {
            if (_entityIDToIndex.find(entityID) != _entityIDToIndex.end())
            {
                return true;
            }

            return false;
        }

        void v_EntityDestroyed(EntityID entityID) override
        {
            if (_entityIDToIndex.find(entityID) != _entityIDToIndex.end())
            {
                RemoveData(entityID);
            }
        }

        inline std::size_t GetCount(void)
        {
            return _nextIndex;
        }

    private:
        std::array<T, MAX_ENTITIES> _componentArray;
        std::unordered_map<EntityID, size_t> _entityIDToIndex;
        std::unordered_map<size_t, EntityID> _indexToEntityID;
        std::size_t _nextIndex;
    };
}