#include "IndexBuffer.h"

namespace Engine {
	namespace Graphics{
		IndexBuffer::IndexBuffer(const unsigned int& count, unsigned int* data)
			:size(size)
		{
			GLCall(glGenBuffers(1, &IBufferID));
			bind();
			GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
			unbind();

		}
		IndexBuffer::~IndexBuffer() 
		{
			GLCall(glDeleteBuffers(1, &IBufferID));
		}

		void IndexBuffer::bind()
		{
			GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBufferID));
		}
		void IndexBuffer::unbind()
		{
			GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
		}
	}
}