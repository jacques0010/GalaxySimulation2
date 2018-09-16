#pragma once
#include <iostream>

#include "MathVector.h"

namespace Engine {
	namespace Math {
		class Matrix4f
		{
		private:
		#define MATRIX4F_ROW_SIZE 4
		#define MATRIX4F_COLUMN_SIZE 4
		#define MATRIX4F_SIZE (MATRIX4F_COLUMN_SIZE * MATRIX4F_ROW_SIZE)
			float data[MATRIX4F_SIZE];
		private:
			Matrix4f();
		public:
			~Matrix4f();

			static Matrix4f Identity();
			static Matrix4f Translate(const Vec3f& vector);
			static Matrix4f RotateZ(float rad);
			static Matrix4f Ortho(float right, float left, float top, float bottom, float far, float near);
			

			Matrix4f multiply(const Matrix4f& other);

			//friend Matrix4f operator*(const Matrix4f& left, const Matrix4f& right) 
			//{
			//	return left.multiply(right);
			//}
			Matrix4f& operator*=(const Matrix4f& other);

			void setData(int index, float value);
			
			inline float* getData()
			{
				return data;
			}
		};
	}
}