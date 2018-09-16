#include "Vec2f.h"

namespace Engine {
	namespace Math {
		Vec2f::Vec2f(float x, float y) 
			: x(x), y(y)
		{}

		Vec2f::~Vec2f(){}

		float Vec2f::dotProduct(const Vec2f& right) const
		{
			return x * right.x + y * right.y;
		}
	}
}