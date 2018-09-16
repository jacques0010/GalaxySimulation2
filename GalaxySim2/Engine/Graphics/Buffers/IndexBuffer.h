#pragma once
#include <glew.h>
#include "..\..\ErrorHandler\ErrorHandlers.h"

namespace Engine {
	namespace Graphics {
		class IndexBuffer {
		private: 
			unsigned int IBufferID;
			const unsigned int size;
		public: 
			IndexBuffer(const unsigned int& size, unsigned int* data);
			~IndexBuffer();

			void bind();
			void unbind();
		};
	}
}