#pragma once
#ifndef _VECTOR3_H_
#define _VECTOR3_H_

namespace Engine
{
	namespace Math
	{
		class Vector3
		{
		public:

			/*============================
			*	CTOR
			============================*/
			Vector3();
			Vector3(float);
			Vector3(float, float);

			/*============================
			*	PUBLIC FUNCTIONS
			============================*/
			float Lenght() const;
			float SquaredLenght() const;
			Vector3 Normalize();

			/*============================
			*	OPERATORS
			============================*/
			Vector3& operator=(const Vector3& rhs);
			Vector3& operator+=(const Vector3& rhs);
			Vector3& operator-=(const Vector3& rhs);
			Vector3& operator*=(const Vector3& rhs);
			Vector3& operator/=(const Vector3& rhs);
			Vector3 operator+(const Vector3& rhs) const;
			Vector3 operator-(const Vector3& rhs) const;
			Vector3 operator*(const Vector3& rhs) const;
			Vector3 operator/(const Vector3& rhs) const;
			bool	operator==(const Vector3& rhs) const;
			bool	operator!=(const Vector3& rhs) const;
			friend  Vector3 operator*(float, const Vector3&);
			friend  Vector3 operator*(const Vector3&, float);

			/*============================
			*	MEMBERS
			============================*/
			float x;
			float y;
			float lenght;
		};
	}
}
#endif // !_VECTOR3_H_