#pragma once
#ifndef _ASTEROID_HPP_
#define _ASTEROID_HPP_

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
			Asteroid();
			Asteroid(int, int);
			~Asteroid();

			/*============================
			*		PUBLIC FUNCTION
			============================*/
			void Render();
			void Update();
			void GetSize();

		};

	}
}
#endif // !_ASTEROID_HPP_