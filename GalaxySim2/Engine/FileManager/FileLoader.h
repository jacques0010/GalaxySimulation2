#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "..\ErrorHandler\TextUtils.h"

namespace Engine {
	namespace IO {
			std::string readFile(const std::string& fileName);
	}
}