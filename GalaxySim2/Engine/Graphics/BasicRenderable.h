#pragma once
#include <glew.h>
#include "..\Math\MathVector.h"
#include "Buffers\BufferLayout.h"

namespace Engine {
	namespace Graphics {

		//might create full class for BasicModel
		struct BasicModel {
			float* vertices;
			unsigned int numOfVerts;

			unsigned int* indices;
			unsigned int numOfIndices;

			BufferLayout layout;
		};
		class BasicRenderable {
		protected:
			BasicModel model;
		public:

			virtual ~BasicRenderable() = 0;

			virtual BasicModel& getModel() = 0;

		};
	}
}