#pragma once
#ifndef _BULLET_HPP_
#define _BULLET_HPP_

//
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
			Bullet(Engine::Math::Vector2, Engine::Math::Vector2, float, const int, const int);
			~Bullet();

			/*============================
			*		PUBLIC FUNCTIONS
			============================*/
			void Render();
			void Update(float);

			/*============================
			*		  MEMBERS
			============================*/
			int m_lifeTime;
		};
	}
}
#endif // !_BULLET_HPP_