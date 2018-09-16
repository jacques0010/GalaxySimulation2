#include "BasicRenderer.h"
#include "..\..\Utilities\Function\FunctionPtr.h"

using namespace std::placeholders;

namespace Engine {
	namespace Graphics {
		Drawable::~Drawable() 
		{
			delete renderable;
		}


		int BasicRenderer::addToRenderer(BasicRenderable& obj, BasicShader* shader) 
		{
			BasicModel model = obj.getModel();

			bool incompleteVertexData = (model.vertices == nullptr) || (model.numOfVerts == NULL || 0);
			bool incompleteIndexData = (model.indices == nullptr) || (model.numOfIndices == NULL || 0);
			bool incompleteLayoutData = (model.layout.getElements().size() == 0);

			if (incompleteVertexData || incompleteIndexData || incompleteLayoutData) 
			{
				Console::TextUtils::warningText("Basic Renderable object could not be added to BasicRenderer! The following data is incomplete: " 
					+ incompleteVertexData ? "Vertex Data " : ""
					+ incompleteIndexData ? "Index Data " : "" 
					+ incompleteLayoutData ? "Vertex Layout Data " : "");
				return false;
			}

			VertexBuffer vbo(model.numOfVerts, model.vertices);
			IndexBuffer indexBuffer(model.numOfIndices, model.indices);

			VertexArray vertexArray;
			vertexArray.addBuffer(vbo, model.layout);

			int randomID = rand() & 2147483647;

			while (drawables.find(randomID) != drawables.end())
				randomID = rand() & 2147483647;
			drawables.insert(std::pair<int, Drawable>(randomID, { vertexArray, indexBuffer, shader, model.numOfIndices }));

			return randomID;

		}

		bool BasicRenderer::deleteFromRenderer(const int& id) 
		{
			return drawables.erase(id) > 0 ? true : false;
		}
		void BasicRenderer::render() 
		{
			for (std::map<int, Drawable>::iterator element = drawables.begin(); element != drawables.end(); ++element) 
			{
				element->second.shader->bind();
				element->second.vao.bind();
				element->second.ibo.bind();
				applyShaderInstruction(element->second);
				GLCall(glDrawElements(GL_TRIANGLES, element->second.numIndices, GL_UNSIGNED_INT, 0));
				element->second.shader->unbind();
				element->second.vao.unbind();
				element->second.ibo.unbind();
			}
		}

		bool BasicRenderer::pushShaderIntruction(int objID, std::function<bool(const std::string&, const float&)> func, const std::string& name, const float& value)
		{
			drawables[objID].shaderUniformUpdates.push(Utilities::FunctionPtr<bool(const std::string&, const float&)> ( std::bind((&BasicShader::setUniform1f), drawables[objID].shader, name, value) ));
		}
		bool BasicRenderer::pushShaderIntruction(int objID, std::function<bool(const std::string& , const Math::Vec2f&)> func, const std::string& name, const Math::Vec2f& value)
		{
			drawables[objID].shaderUniformUpdates.push(Utilities::FunctionPtr<bool(const std::string&, const Math::Vec2f&)>{ std::bind((&BasicShader::setUniformVec2), drawables[objID].shader, name, value) });
		}
		bool BasicRenderer::pushShaderIntruction(int objID, std::function<bool(const std::string&, const Math::Vec3f&)>  func, const std::string& name, const Math::Vec3f& value)
		{
			drawables[objID].shaderUniformUpdates.push(Utilities::FunctionPtr<bool(const std::string&, const Math::Vec3f&)>{ std::bind((&BasicShader::setUniformVec3), drawables[objID].shader, name, value) });
		}
		bool BasicRenderer::pushShaderIntruction(int objID, std::function<bool(const std::string&, const Math::Vec4f&)> func, const std::string& name, const Math::Vec4f& value)
		{
			drawables[objID].shaderUniformUpdates.push(Utilities::FunctionPtr<bool(const std::string&, const Math::Vec4f&)> { std::bind((&BasicShader::setUniformVec4), drawables[objID].shader, name, value) });
		}
		bool BasicRenderer::pushShaderIntruction(int objID, std::function<bool(const std::string&, Math::Matrix4f&)> func, const std::string& name, Math::Matrix4f& value )
		{
			drawables[objID].shaderUniformUpdates.push(Utilities::FunctionPtr<bool(const std::string&, Math::Matrix4f&)> { std::bind((&BasicShader::setUniformMat4), drawables[objID].shader, name, value) });
		}
		void BasicRenderer::applyShaderInstruction(Drawable& obj) 
		{
			while(obj.shaderUniformUpdates.empty() == false)
			{
				obj.shaderUniformUpdates.front().call();
				//genFunc.call();
				obj.shaderUniformUpdates.pop();
			}
		}
	}
}