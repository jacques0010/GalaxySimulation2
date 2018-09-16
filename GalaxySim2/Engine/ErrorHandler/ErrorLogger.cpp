#include "ErrorLogger.h"
namespace Engine {
	void clearGLError()
	{
		while (glGetError() != 0);
	}
	int logGlError(const int& lineNumber, const std::string& fileName)
	{
		int error = glGetError();
		if (error != 0) 
			Console::TextUtils::errorText("Opengl error on line: " + std::to_string(lineNumber) + " in " + fileName + " Code:" + std::to_string(error));
		return error == 0 ? 1 : 0;
	}
}