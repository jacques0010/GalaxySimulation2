#pragma once
namespace Engine {
	namespace Math {
		class Vec4f
		{
		public:
			float x, y, z, w;
		public:
			Vec4f(float x, float y, float z, float w);
			~Vec4f();

			float dotProduct(const Vec4f& right) const;

			friend float operator*(const Vec4f& left, const Vec4f& right)
			{
				return left.dotProduct(right);
			}
		};
	}
}