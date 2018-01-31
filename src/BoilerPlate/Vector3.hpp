#pragma once

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

namespace Engine
{
	namespace Math
	{
		struct Vector3
		{
			/*============================
			*	STATIC
			============================*/


			/*============================
			*	CTOR
			============================*/
			Vector3();
			Vector3(float);
			Vector3(float, float);

			/*============================
			*	PUBLIC FUNCTIONS
			============================*/


			/*============================
			*	OPERATORS
			============================*/


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