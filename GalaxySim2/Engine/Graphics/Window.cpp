#include "Window.h"

namespace Engine {
	namespace Graphics {
		OGLWindow::OGLWindow(int sizeX, int sizeY, const char* windowName) 
			:m_window_ptr(glfwCreateWindow(sizeX, sizeY, windowName, NULL, NULL))
		{}

		int OGLWindow::init()
		{
			if (m_window_ptr == nullptr) {
				glfwTerminate();
				Console::TextUtils::errorText("Window could not be created!");
				return -1;
			}
			glfwMakeContextCurrent(m_window_ptr);
			if (glewInit() != GLEW_OK) {
				glfwTerminate();
				Console::TextUtils::errorText("GLEW could not initailize!");
				return -1;
			}
			return 1;
		}
	}
}