#include "Matrix4f.h"

namespace Engine {
	namespace Math {
		Matrix4f::Matrix4f()
		{
			memset(data, 0, sizeof(data));
		}
		Matrix4f::~Matrix4f()
		{
		}

		Matrix4f Matrix4f::Identity()
		{
			Matrix4f result;
			result.data[0 + 0 * 4] = 1;
			result.data[1 + 1 * 4] = 1;
			result.data[2 + 2 * 4] = 1;
			result.data[3 + 3 * 4] = 1;
			return result;
		}

		Matrix4f Matrix4f::Translate(const Vec3f& vector)
		{
			Matrix4f result = Identity();
			result.data[0 + 3 * 4] = vector.x;
			result.data[1 + 3 * 4] = vector.y;
			result.data[2 + 3 * 4] = vector.z;
			return result;
		}
		Matrix4f Matrix4f::RotateZ(float rad) 
		{
			float cos = std::cos(rad);
			float sin = std::sin(rad);

			Matrix4f result = Identity();
			result.data[0 + 0 * 4] = cos;
			result.data[1 + 0 * 4] = sin;
			result.data[0 + 1 * 4] = -sin;
			result.data[1 + 1 * 4] = cos;
			return result;

		}

		Matrix4f Matrix4f::Ortho(float right, float left, float top, float bottom, float far, float near)
		{
			Matrix4f result;
			result.data[0 + 0 * 4] =  2  / (right - left);
			result.data[1 + 1 * 4] =  2  / (top   - bottom);
			result.data[2 + 2 * 4] = -2  / (far   - near);
			result.data[0 + 3 * 4] = - (right + left)   / (right - left);
			result.data[1 + 3 * 4] = - (top   + bottom) / (top   - bottom);
			result.data[2 + 3 * 4] = - (far   + near)   / (near  - far);
			result.data[3 + 3 * 4] = 1;
			return result;
		}

		Matrix4f Matrix4f::multiply(const Matrix4f& other) 
		{
			Matrix4f result;
			float sum;
			for (int column = 0; column < MATRIX4F_ROW_SIZE; column++)
			{
				for (int row = 0; row < MATRIX4F_COLUMN_SIZE; row++)
				{
					sum = 0;
					for (int element = 0; element < MATRIX4F_COLUMN_SIZE; element++)
					{
						sum += data[element + column * MATRIX4F_COLUMN_SIZE] * other.data[row + element * MATRIX4F_COLUMN_SIZE];
					}
					result.data[row + column * MATRIX4F_COLUMN_SIZE] = sum;
				}
			}
			return result;
		}
		
		void Matrix4f::setData(int index, float value)
		{
			data[index] = value;
		}
	}
}