#include "VertexArray.h"

namespace Engine {
	namespace Graphics {
		VertexArray::VertexArray() 
		{
			GLCall(glCreateVertexArrays(1, &vao));

		}
		VertexArray::~VertexArray() 
		{
			GLCall(glDeleteVertexArrays(1, &vao));
		}

		void VertexArray::addBuffer(const VertexBuffer& buffer, const BufferLayout& layout)
		{
			buffer.bind();
			bind();
			unsigned int offset = 0;
			GLCall(glEnableVertexAttribArray(0));
			const std::vector<BufferLayoutElement>& elements = layout.getElements();
			for(int i = 0; i < elements.size(); i++)
			{
				GLCall(glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, elements[i].sizeInBytes, (void*)offset));
				offset += elements[i].sizeInBytes;
			}
			unbind();
		}

		void VertexArray::bind()
		{
			glBindVertexArray(vao);
		}
		
		void VertexArray::unbind()
		{
			GLCall(glBindVertexArray(0));
		}

	}
}