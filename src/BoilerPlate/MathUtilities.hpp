#pragma once
#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <iostream>
#include <algorithm>
#include <string>

//
#include "Constants.hpp"

namespace Engine
{
	namespace Math
	{
		class MathUtilities
		{
		public:
			/*====================
			*	PUBLIC FUNCTIONS
			======================*/
			inline int GetNearestInt(int);
			inline float RoundFloatToInt(float);
			template<class T> T MaximumN(T arr[4]);
			template<class T> T MinimumN(T arr[4]);
			template<class T> T Clamp(T);
			template<class T> T Interpolate(T);
			static float ConvertRadToDegrees(float);
			static float ConvertDegreesToRad(float);
			inline int IsPowerOfTwo(int);
			double AngularDistances(double, double);

			/*======================
			*		MEMBERS
			======================*/
			float m_intToFloat;
			int m_floatToInt;
		};
	}
}
#endif // !_MATH_HPP_