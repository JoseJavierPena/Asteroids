#pragma once
#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <iostream>
#include <algorithm>
#include <string>

namespace Engine
{
	namespace Math
	{
		class MathUtilities
		{
		public:

			/*====================
			*	CONST
			======================*/
			const float PI = 3.1415926535897323846f;

			/*====================
			*	PUBLIC FUNCTIONS
			======================*/
			MathUtilities();
			~MathUtilities();

			inline int GetNearestInt(int);
			inline float RoundFloatToInt(float);
			template<class T> T MaximumN(T arr[4]);
			template<class T> T MinimumN(T arr[4]);
			template<class T> T Clamp(T);
			template<class T> T Interpolate(T);
			float ConvertRadToDegrees(float);
			float ConvertDegreesToRad(float);
			inline int IsPowerOfTwo(int);
			double AngularDistances(double, double);

			/*======================
			*		MEMBERS
			======================*/
			float m_intToFloat;
			int m_floatToInt;
			// float m_radians;
			// float m_degrees;
		};
	}
}
#endif // !_MATH_HPP_