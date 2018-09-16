#include "BasicShader.h"

namespace Engine {
	namespace Graphics {
		BasicShader::BasicShader(const std::string& vShaderPath, const std::string& fShaderPath) 
		{
			GLCall(m_ShaderID = glCreateProgram());
			m_vertexShader = compileShaders(vShaderPath, GL_VERTEX_SHADER);
			m_fragmentShader = compileShaders(fShaderPath, GL_FRAGMENT_SHADER);
			GLCall(glAttachShader(m_ShaderID, m_vertexShader));
			GLCall(glAttachShader(m_ShaderID, m_fragmentShader));
			GLCall(glLinkProgram(m_ShaderID));

			//think about putting error checking into function
			int isLinked;
			GLCall(glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &isLinked));
			if (isLinked != GL_TRUE)
			{
				int logLength = 0;
				char message[1024];
				GLCall(glGetProgramInfoLog(m_ShaderID, 1024, &logLength, message));
				Console::TextUtils::errorText(message);
				m_ShaderID = 0;
			}
			GLCall(glDeleteShader(m_vertexShader));
			GLCall(glDeleteShader(m_fragmentShader));
		}

		BasicShader::~BasicShader()
		{
			GLCall(glDeleteProgram(m_ShaderID));
		}

		bool BasicShader::setUniform1f(const std::string& name, const float& value)
		{
			if (locationCache.find(name) == locationCache.end()) {
				GLCall(locationCache[name] = glGetUniformLocation(m_ShaderID, name.c_str()));
				if (locationCache[name] == -1)
				{
					locationCache.erase(name);
					return false;
				}
			}
			GLCall(glUniform1f(locationCache[name], value));
			return true;
		}
		bool BasicShader::setUniformVec2(const std::string& name, const Math::Vec2f& value)
		{
			if (locationCache.find(name) == locationCache.end()) {
				GLCall(locationCache[name] = glGetUniformLocation(m_ShaderID, name.c_str()));
				if (locationCache[name] == -1)
				{
					locationCache.erase(name);
					return false;
				}
			}
			GLCall(glUniform2f(locationCache[name], value.x, value.y));
			return true;
		}
		bool BasicShader::setUniformVec3(const std::string& name, const Math::Vec3f& value)
		{
			if (locationCache.find(name) == locationCache.end()) {
				GLCall(locationCache[name] = glGetUniformLocation(m_ShaderID, name.c_str()));
				if (locationCache[name] == -1)
				{
					locationCache.erase(name);
					return false;
				}
			}
			GLCall(glUniform3f(locationCache[name], value.x, value.y, value.z));
			return true;

		}
		bool BasicShader::setUniformVec4(const std::string& name, const Math::Vec4f& value)
		{
			if (locationCache.find(name) == locationCache.end()) {
				GLCall(locationCache[name] = glGetUniformLocation(m_ShaderID, name.c_str()));
				if (locationCache[name] == -1)
				{
					locationCache.erase(name);
					return false;
				}
			}
			GLCall(glUniform4f(locationCache[name], value.x, value.y, value.z, value.w));
			return true;

		}
		bool BasicShader::setUniformMat4(const std::string& name, Math::Matrix4f& value)
		{
			if (locationCache.find(name) == locationCache.end()) {
				GLCall(locationCache[name] = glGetUniformLocation(m_ShaderID, name.c_str()));
				if (locationCache[name] == -1)
				{
					locationCache.erase(name);
					return false;
				}
			}
			GLCall(glUniformMatrix4fv(locationCache[name], 1, GL_FALSE, value.getData()));
			return true;

		}

		void BasicShader::bind()
		{
			GLCall(glUseProgram(m_ShaderID));
		}
		void BasicShader::unbind()
		{
			GLCall(glUseProgram(0));
		}


		unsigned int BasicShader::compileShaders(const std::string& path, unsigned int type)
		{
			unsigned int shader;
			GLCall(shader = glCreateShader(type));
			std::string shaderSource = IO::readFile(path); /*type == GL_VERTEX_SHADER ? "#version 330\n in vec4 position;\n void main() {\n gl_Position = position;\n }\n" : "#version 330\nout vec4 color;\nvoid main()\n{\ncolor = (1.0f, 1.0f, 0.0f, 1.0f);\n}\n";*/
			const char* source = shaderSource.c_str();
			GLCall(glShaderSource(shader, 1, &source, NULL));
			GLCall(glCompileShader(shader));

			int isCompiled;
			GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled));
			if (isCompiled != GL_TRUE) 
			{
				int logLength = 0;
				char message[1024];
				GLCall(glGetShaderInfoLog(shader, 1024, &logLength, message));
				Console::TextUtils::errorText(message);
				return 0;
			}
			return shader;
		}
	}
}