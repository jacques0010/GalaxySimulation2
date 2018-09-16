#pragma once
#include <glew.h>
#include <glfw3.h>
#include "..\ErrorHandler\TextUtils.h"

namespace Engine {
	namespace Graphics {
		class OGLWindow
		{
		private:
			GLFWwindow* m_window_ptr;
		public:
			OGLWindow(int sizeX, int sizeY, const char* windowName);

			int init();

			inline GLFWwindow* getWindow() { return m_window_ptr; }
		};

	}
}