#pragma once
#include <glew.h>
#include <string>
#include <unordered_map>
#include "..\Math\MathVector.h"
#include "..\Math\Matrix4f.h"
#include "..\FileManager\FileLoader.h"
#include "..\ErrorHandler\ErrorHandlers.h"
 
//will think about extending this class to form more complex shaders. Think about factory method to create programs;
namespace Engine {
	namespace Graphics {
		class BasicShader {
		private: 
			std::unordered_map<std::string, int> locationCache;
			unsigned int m_ShaderID;
			unsigned int m_vertexShader;
			unsigned int m_fragmentShader;
		public:
			BasicShader(const std::string& vShaderPath, const std::string& fShaderPath);
			~BasicShader();

			void bind();
			void unbind();

			bool setUniform1f(const std::string& name, const float& value);
			bool setUniformVec2(const std::string& name, const Math::Vec2f& value);
			bool setUniformVec3(const std::string& name, const Math::Vec3f& value);
			bool setUniformVec4(const std::string& name, const Math::Vec4f& value);
			bool setUniformMat4(const std::string& name, Math::Matrix4f& value);

			inline unsigned int getShader() { return m_ShaderID; }
		
		private:
			unsigned int compileShaders(const std::string& path, unsigned int type);
		};
			
	}
}