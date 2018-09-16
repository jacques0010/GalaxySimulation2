#include "Engine/Graphics/Window.h"
#include <iostream>
#include "Engine/ErrorHandler/ErrorHandlers.h"
#include "Engine/FileManager/FileLoader.h"
#include "Engine/Graphics/Buffers/IndexBuffer.h"
#include "Engine/Graphics/Buffers/VertexBuffer.h"
#include "Engine/Graphics/Buffers/VertexArray.h"
#include "Engine/Graphics/Buffers/BufferLayout.h"
#include "Engine/Graphics/BasicShader.h"
#include "Engine/Math/Matrix4f.h"
#include "Engine/Graphics/Renderers/BasicRenderer.h"

#include "Game/Rectangle.h"


using namespace Engine;

int main() {
	{
		unsigned int index[] = {
			0, 1, 2,
			2, 3, 0

		};

		float positions[] =
		{
			 1.0f,  1.0f,
			-1.0f,  1.0f,
			-1.0f, -1.0f,
			 1.0f, -1.0f

		};

		Math::Matrix4f projection = Math::Matrix4f::Ortho(-10.0f, 10.0f, -10.0f * 9.0f / 16.0f, 10.0f * 9.0f / 16.0f, -1.0f, 1.0f);
		Math::Matrix4f translation = Math::Matrix4f::Translate({ 1.0, 2.0, 0.0 });

		


		if (!glfwInit())
		{
			return -1;
		}


		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		Graphics::OGLWindow window = Graphics::OGLWindow(1280, 720, "Window");
		if (!window.init()) std::cin.get();

		Game::Rectangle rect(1, 1);
		Graphics::BasicShader shader("Shaders/basicVert.shader", "Shaders/basicFrag.shader");

		Graphics::BasicRenderer renderer;
		int rectID = renderer.addToRenderer(rect, &shader);
		//renderer.pushShaderIntruction(rectID, Graphics::BasicShader::setUniformMat4, "projection", projection);
		//renderer.pushShaderIntruction(rectID, Graphics::BasicShader::setUniformMat4, "translation", translation);
		//Graphics::IndexBuffer indexBuffer(6, index);
		//Graphics::VertexBuffer vertexBuffer(8, positions);
		//Graphics::BufferLayout layout;
		//layout.push<float>(2, GL_FALSE);
		//Graphics::VertexArray vertexArray;
		//vertexArray.addBuffer(vertexBuffer, layout);
		/*vertexBuffer.bind();
		unsigned int vao;
		GLCall(glCreateVertexArrays(1, &vao));
		GLCall(glEnableVertexAttribArray(0));
		GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));*/



		while (!glfwWindowShouldClose(window.getWindow()))
		{
			GLCall(glClear(GL_COLOR_BUFFER_BIT));
			//GLCall(glBindVertexArray(vao));
			//vertexArray.bind();
			//vertexBuffer.bind();
			//indexBuffer.bind();
			//shader.bind();
			//shader.setUniform("projection", projection);
			//shader.setUniform("translation", translation);
			//GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
			
			renderer.render();
			GLCall(glfwSwapBuffers(window.getWindow()));

			GLCall(glfwPollEvents());
		}
	}
	glfwTerminate();
}
