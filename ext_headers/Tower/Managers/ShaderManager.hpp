#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Shader.hpp"
#include <map>

namespace Tower
{
    class ShaderManager
    {
    public:
        ShaderManager(void);

        ~ShaderManager(void);

        void LoadShader(const string& shaderName, const string& vertexFilepath, const string& fragmentFilepath);

        void RegisterShader(const string& shaderName, p_Shader shader);

        p_Shader GetShader(const string& shaderName);

    private:
        std::map<const char*, p_Shader> _shaders;
    };
    typedef shared_ptr<ShaderManager> p_ShaderManager;
}