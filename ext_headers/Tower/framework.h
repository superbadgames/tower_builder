#pragma once

#ifdef TOWER_EXPORTS
#define TOWER_API __declspec(dllexport)
#else
#define TOWER_API __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN


// Windows Header Files
#include <windows.h>

extern "C" {
#include <glad/glad.h>
#include <GLFW/glfw3.h>
}

// stl global includes
#include <cstdint>
#include <memory>
#include <string>
#include <bitset>

namespace Tower
{
    using std::shared_ptr;
    using std::string;
    using std::unique_ptr;

    // Custom typedefs
    typedef int8_t S8;
    typedef int16_t S16;
    typedef int32_t S32;
    typedef int64_t S64;
    typedef uint8_t U8;
    typedef uint16_t U16;
    typedef uint32_t U32;
    typedef uint64_t U64;
    typedef float F32;
    typedef double F64;
    // Seprate because sometimes we want to be able to change just what a real number is.
    // Also use this wherever you are talking about a real number. Only use F32 when you
    // need a 32 bit floating point number SPECIFICALLY.
    typedef float real;

#define REAL_MAX FLT_MAX
#define real_sqrt sqrtf
#define real_abs fabsf
#define real_sin sinf
#define real_cos cosf
#define real_tan tanf
#define real_atan atanf
#define real_atan2 atan2f
#define real_exp expf
#define real_pow powf
#define real_fmod fmod4
#define real_epsilon DBL_EPSILON

    const real R_PI = static_cast<real>(3.14159265358979);

    //==========================================================================================================================
    // Global Helper functions
    //==========================================================================================================================

    using EntityID = U32;
    // TODO: This should be moved into a config file, loaded from the runtime application.
    const EntityID MAX_ENTITIES = 5000;

    using ComponentType = U8;

    // TODO: This too.
    const ComponentType MAX_COMPONENTS = 32;

    using Signature = std::bitset<MAX_COMPONENTS>;

    inline real REAL_SQR(real x)
    {
        return x * x;
    }

    inline real RADIAN(real angle)
    {
        return static_cast<real>(angle * R_PI / 180.0f);
    }

    inline real DEGREE(real radian)
    {
        return static_cast<real>(radian * 180.0f / R_PI);
    }

    inline real REAL_CLAMP(real val, real min, real max)
    {
        if (val < min)
        {
            return min;
        }
        else if (val > max)
        {
            return max;
        }
        else
        {
            return val;
        }
    }
}