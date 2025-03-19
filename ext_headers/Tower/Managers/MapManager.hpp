/*

The Tower Map is a Map that represents either part of all of a world. It is the interface used to:

- load maps from memory
- Keep track of an Active Map, that is the current Map that the "player" is on


*/

#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Components/Map.hpp"

#include <map>

namespace Tower
{
    class MapManager
    {
    public:
        ~MapManager(void);

        static shared_ptr<MapManager> Instance(void);

        void Add(const string& name, p_Map map);

        void Remove(const string& name);

        void SetActiveMap(const string& name);

        void UpdateActiveMap(F32 delta);

        void RenderActiveMap(void);

    private:
        static shared_ptr<MapManager> _instance;
        p_Map _activeMap;
        std::map<string, p_Map> _mapRegistry;

        MapManager(void);
    };
    typedef shared_ptr<MapManager> p_MapManager;
}