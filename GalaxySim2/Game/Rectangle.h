#pragma once
#include "..\Engine\Graphics\BasicRenderable.h"
#include "..\Engine\Math\Vec3f.h"
#include "..\Engine\Math\Matrix4f.h"

using namespace Engine;

namespace Game {
	class Rectangle : public Graphics::BasicRenderable
	{
	private:
		float height, width;

		Math::Vec3f position = {0, 0, 0};

		float positions[8] =
		{
			height * 1.0f,  width * 1.0f,
			height *-1.0f,  width * 1.0f,
			height *-1.0f,  width *-1.0f,
			height * 1.0f,  width *-1.0f
		};

		unsigned int index[6] = {
			0, 1, 2,
			2, 3, 0
		};
	public:

		Rectangle(float height, float width)
			: height(height), width(width)
		{
			model.layout.push<float>(2, GL_FALSE);
			model.indices = index;
			model.numOfIndices = 6;
			model.vertices = positions;
			model.numOfVerts = 8;
		}
		Rectangle()
			: height(1), width(1)
		{}

		Graphics::BasicModel& getModel() 
		{
			return BasicRenderable::model;
		}
	};
}