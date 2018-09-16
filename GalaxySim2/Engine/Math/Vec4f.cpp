#include "Vec4f.h"

namespace Engine {
	namespace Math {
		Vec4f::Vec4f(float x, float y, float z, float w) 
			: x(x), y(y), z(z), w(w)
		{}

		Vec4f::~Vec4f() {}

		float Vec4f::dotProduct(const Vec4f& right) const 
		{
			return x * right.x + y * right.y + z * right.z + w * right.w;
		}
	}
}