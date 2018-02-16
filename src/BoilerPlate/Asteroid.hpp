#pragma once
#ifndef _ASTEROID_HPP_
#define _ASTEROID_HPP_

#include "Vector2.hpp"

namespace Asteroids
{
	namespace Entities
	{
		class Asteroid
		{
		public:

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
			void Update();
			void GetSize();

			/*============================
			*		  MEMBERS
			============================*/
			Engine::Math::Vector2* m_position;
			float m_width;
			float m_height;

		};

	}
}
#endif // !_ASTEROID_HPP_