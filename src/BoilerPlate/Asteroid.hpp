#pragma once
#ifndef _ASTEROID_HPP_
#define _ASTEROID_HPP_

//
#include "Vector2.hpp"
#include "Entity.hpp"
#include "Constants.hpp"

namespace Asteroids
{
	namespace Entities
	{
		class Asteroid : Entity
		{
		public:

			/*============================
			*	  	  ENUMERATOR
			============================*/
			struct AsteroidSize
			{
				enum SIZE
				{
					SMALL = 1,
					MEDIUM = 5,
					BIG = 10,
				};
			};

			/*============================
			*			CTOR
			============================*/
			Asteroid(int, int);

			/*============================
			*		PUBLIC FUNCTION
			============================*/
			void Render();
			void Update(float);
			AsteroidSize::SIZE GetSize() { return m_size; };
			Engine::Math::Vector2 GetPosition() { return m_position; };


			/*============================
			*		  MEMBERS
			============================*/
			Engine::Math::Vector2 m_position;
			float m_width;
			float m_height;
			Asteroid::AsteroidSize::SIZE m_size;
			float m_angle;
			float m_mass;
			//float m_radius;
			//float m_angle;
			Engine::Math::Vector2 m_velocity;
		};

	}
}
#endif // !_ASTEROID_HPP_