#pragma once
namespace Engine {
	namespace Math {
		class Vec3f {
		public:
			float x, y, z;
		public:
			//todo: add cross product
			Vec3f(float x, float y, float z);
			~Vec3f();

			inline static Vec3f unitVec3f() 
			{
				return Vec3f{ 1, 1, 1 };
			}

			float dotProduct(const Vec3f& right) const;

			Vec3f cross(const Vec3f& other) const;

			friend float operator*(const Vec3f& left, const Vec3f& right) 
			{
				return left.dotProduct(right);
			}

		};
	}
}