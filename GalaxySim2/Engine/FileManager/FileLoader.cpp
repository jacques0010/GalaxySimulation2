#include "FileLoader.h"

namespace Engine {
	namespace IO {
		std::string readFile(const std::string& fileName) 
		{
			std::ifstream file(fileName);
			std::stringstream result;
			std::string line;
			if (!file.is_open()) {
				Console::TextUtils::errorText("File \"" + fileName + "\" could not be opened! Returning empty string!");
				return " ";
			}
			while (getline(file, line)) {
				result << line << "\n";
			}
			return result.str();
		}
	}
}