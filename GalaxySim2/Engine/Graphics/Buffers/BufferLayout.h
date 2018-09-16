#pragma once
#include <glew.h>
#include <vector>

namespace Engine {
	namespace Graphics {
		struct BufferLayoutElement {
			unsigned int count;
			unsigned int sizeInBytes;
			unsigned int type;
			unsigned int normalized;
		};

		class BufferLayout 
		{
		private:
			std::vector<BufferLayoutElement> m_Elements;
		public:
			BufferLayout();
			~BufferLayout();

			template<typename type>
			void push(unsigned int count, GLenum normalized) 
			{
				static_assert(false);
			}

			template<>
			void push<float>(unsigned int count, GLenum normalized)
			{
				m_Elements.push_back({ count, count * sizeof(float), GL_FLOAT, normalized });
			}
			
			template<>
			void push<int>(unsigned int count, GLenum normalized)
			{
				m_Elements.push_back({ count, count * sizeof(int),GL_INT, normalized });
			}
			
			template<>
			void push<unsigned int>(unsigned int count, GLenum normalized)
			{
				m_Elements.push_back({ count, count * sizeof(unsigned int),GL_UNSIGNED_INT, normalized });
			}

			inline std::vector<BufferLayoutElement> getElements() const { return m_Elements; }
		};
	}
}