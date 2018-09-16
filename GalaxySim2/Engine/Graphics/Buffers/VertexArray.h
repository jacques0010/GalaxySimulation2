#pragma once
#include <glew.h>
#include <vector>
#include "..\..\ErrorHandler\ErrorHandlers.h"
#include "BufferLayout.h"
#include "VertexBuffer.h"
namespace Engine {
	namespace Graphics {
		class VertexArray 
		{
		private:
			unsigned int vao;
			BufferLayout bufferLayout;
		public:

			VertexArray();
			~VertexArray();

			void addBuffer(const VertexBuffer& buffer, const BufferLayout& layout);

			void bind();
			void unbind();
		};
	}
}