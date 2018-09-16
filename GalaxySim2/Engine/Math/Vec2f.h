#pragma once

namespace Engine {
	namespace Math {
		
		class Vec2f
		{
		public:
			float x, y;

		public:
			Vec2f(float x, float y);
			~Vec2f();

			inline static Vec2f unitVec2f() { return Vec2f{ 1, 1 }; }

			float dotProduct(const Vec2f& right) const;
	
			friend float operator*(const Vec2f& left, const Vec2f& right)
			{
				return left.dotProduct(right);
			}
			
		};
	}
}