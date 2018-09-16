#pragma once
#include "TextUtils.h"
#include "ErrorLogger.h"
#define ASSERT(x) if(!x) __debugbreak();
#define GLCall(x) {Engine::clearGLError(); (x); ASSERT(Engine::logGlError(__LINE__, __FILE__))}
//#define GLCall(x) x