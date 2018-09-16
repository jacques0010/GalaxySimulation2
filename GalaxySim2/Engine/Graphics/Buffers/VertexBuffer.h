#pragma once
#include <glew.h>
#include "..\..\ErrorHandler\ErrorHandlers.h"

namespace Engine {
	namespace Graphics {
		class VertexBuffer {
		private:
			unsigned int VBufferID;
			const unsigned int size;
		public:
			VertexBuffer(const unsigned int& size, float* data);
			~VertexBuffer();

			void bind() const;
			void unbind() const;
		};
	}
}