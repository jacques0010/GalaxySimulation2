#pragma once
#include <glew.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <queue>
#include <functional>
#include "..\..\Math\MathLib.h"
#include "..\..\Utilities\Function\FunctionPtr.h"
#include "..\..\ErrorHandler\ErrorHandlers.h"
#include "..\BasicRenderable.h"
#include "..\Buffers\VertexArray.h"
#include "..\Buffers\VertexBuffer.h"
#include "..\Buffers\IndexBuffer.h"
#include "..\BasicShader.h"

namespace Engine {
	namespace Graphics {
		struct Drawable {
			~Drawable();
			VertexArray vao;
			IndexBuffer ibo;
			BasicShader* shader;

			unsigned int numIndices;
			BasicRenderable* renderable;

			std::queue<Utilities::genericFunction> shaderUniformUpdates;
		};
		class BasicRenderer {
		private:
			std::map<int, Drawable> drawables;
		public:
			
			//todo: add compatibility for different types of shader
			bool pushShaderIntruction(int objID, std::function<bool(const std::string&, const float&)> func, const std::string& name, const float&);
			bool pushShaderIntruction(int objID, std::function<bool(const std::string&, const Math::Vec2f&)> func, const std::string& name, const Math::Vec2f&);
			bool pushShaderIntruction(int objID, std::function<bool(const std::string&, const Math::Vec3f&)>  func, const std::string& name, const Math::Vec3f&);
			bool pushShaderIntruction(int objID, std::function<bool(const std::string&, const Math::Vec4f&)> func, const std::string& name, const Math::Vec4f&);
			bool pushShaderIntruction(int objID, std::function<bool(const std::string&, Math::Matrix4f&)> func, const std::string& name, Math::Matrix4f& value);
			//bool pushShaderIntruction(int objID, BasicShader::* func, const std::string& name, Math::Matrix4f& value);
			int addToRenderer(BasicRenderable& obj, BasicShader* shader);
			bool deleteFromRenderer(const int& id);
			void render();
		private:
			void applyShaderInstruction(Drawable& obj);
		};
	}
}