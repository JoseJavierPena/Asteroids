#pragma once
#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

#include "Vector2.hpp"

namespace Consts
{
		/*============================
		*		  MEMBERS
		============================*/
		const float THRUST = 1.5;
		const float ANGLE_OFFSET = 90.0f;
		const float DRAG = 0.9f;
		const float PI = 3.14159f;

		// For the Asteroid
		const int MAX_POINTS = 12;
		const float MAX_SIZE = 30.f;
		const float MIN_SIZE = 20.f;
		const float MAX_SPEED_BIG_ASTEROID = 2.5f;
		const float MAX_SPEED_MED_ASTEROID = 3.f;
		const float MAX_SPEED_SMALL_ASTEROID = 3.25f;

		// For Player Ship
		const int MAX_BULLETS = 30;
		const float MAX_SPEED_PLAYER = 10.f;

		//For Bullets
		const float MAX_SPEED_BULLET = 4.5f;
}
#endif // !_CONSTANTS_HPP_