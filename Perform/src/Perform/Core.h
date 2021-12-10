#pragma once


#define BIT(val) (1 << val)
#define PF_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// TODO: Move assertions to debug builds
#define PF_ENABLE_ASSERTIONS 1

#ifdef PF_ENABLE_ASSERTIONS
#define PF_CORE_ASSERT(val, ...) {if(!(val)) {PF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#define PF_ASSERT(val, ...) {if(!(val)) {PF_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
#define PF_CORE_ASSERT(val, ...)
#define PF_ASSERT(val, ...)
#endif