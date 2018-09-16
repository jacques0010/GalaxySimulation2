#pragma once
#include <glew.h>
#include <string>
#include "TextUtils.h"


namespace Engine {
	void clearGLError();
	int logGlError(const int& lineNumber, const std::string& fileName);
}