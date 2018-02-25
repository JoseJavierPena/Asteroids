#pragma once
#ifndef _BULLET_HPP_
#define _BULLET_HPP_

#include "Entity.hpp"
#include "MathUtilities.hpp"
#include "Vector2.hpp"

namespace Asteroids
{
	namespace Entities
	{
		class Bullet : Entity
		{
		public:
			/*============================
			*			CTOR
			============================*/
			Bullet();
			~Bullet();

			/*============================
			*		PUBLIC FUNCTIONS
			============================*/
			void Render();
			void Update(float);
		};
	}
}
#endif // !_BULLET_HPP_