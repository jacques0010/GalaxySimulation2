#include "Vec3f.h"

namespace Engine {
	namespace Math {
		Vec3f::Vec3f(float x, float y, float z)
			: x(x), y(y), z(z)
		{}

		Vec3f::~Vec3f() {}

		float Vec3f::dotProduct(const Vec3f& right) const
		{
			return x * right.x + y * right.y + z * right.z;
		}

		Vec3f Vec3f::cross(const Vec3f& other) const
		{
			return { y * other.z - z * other.y,
					z * other.x - x * other.z,
					x * other.y - y * other.x };
		}
	}
}