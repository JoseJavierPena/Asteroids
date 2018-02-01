#include "Vector3.hpp"

namespace Engine
{
	namespace Math
	{
		Vector3::Vector3()
		{
		}
		Vector3::Vector3(float)
		{
		}
		Vector3::Vector3(float, float)
		{
		}
		float Vector3::Lenght() const
		{
			return 0.0f;
		}
		float Vector3::SquaredLenght() const
		{
			return 0.0f;
		}
		Vector3 Vector3::Normalize()
		{
			return Vector3();
		}
		Vector3 & Vector3::operator=(const Vector3 & rhs)
		{
			// TODO: insert return statement here
		}
		Vector3 & Vector3::operator+=(const Vector3 & rhs)
		{
			// TODO: insert return statement here
		}
		Vector3 & Vector3::operator-=(const Vector3 & rhs)
		{
			// TODO: insert return statement here
		}
		Vector3 & Vector3::operator*=(const Vector3 & rhs)
		{
			// TODO: insert return statement here
		}
		Vector3 & Vector3::operator/=(const Vector3 & rhs)
		{
			// TODO: insert return statement here
		}
		Vector3 Vector3::operator+(const Vector3 & rhs) const
		{
			return Vector3();
		}
		Vector3 Vector3::operator-(const Vector3 & rhs) const
		{
			return Vector3();
		}
		Vector3 Vector3::operator*(const Vector3 & rhs) const
		{
			return Vector3();
		}
		Vector3 Vector3::operator/(const Vector3 & rhs) const
		{
			return Vector3();
		}
		bool Vector3::operator==(const Vector3 & rhs) const
		{
			return false;
		}
		bool Vector3::operator!=(const Vector3 & rhs) const
		{
			return false;
		}
		Vector3 operator*(float, const Vector3 &)
		{
			return Vector3();
		}
		Vector3 operator*(const Vector3 &, float)
		{
			return Vector3();
		}
	}
}
