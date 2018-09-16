#include "VertexBuffer.h"

namespace Engine {
	namespace Graphics {
		VertexBuffer::VertexBuffer(const unsigned int& count, float* data)
			:size(size)
		{
			GLCall(glGenBuffers(1, &VBufferID));
			bind();
			GLCall(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW));
			unbind();

		}
		VertexBuffer::~VertexBuffer()
		{
			/*std::cout << glGetError() << std::endl;*/
			GLCall(glDeleteBuffers(1, &VBufferID));
		}

		void VertexBuffer::bind() const
		{
			GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBufferID));
		}
		void VertexBuffer::unbind() const
		{
			GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
		}
	}
}