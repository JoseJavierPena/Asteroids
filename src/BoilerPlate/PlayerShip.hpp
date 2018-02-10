#pragma once
#ifndef _PLAYER_SHIP_HPP_
#define _PLAYER_SHIP_HPP_

#include "Vector2.hpp"

namespace Asteroids
{
	namespace Entities
	{
		class PlayerShip
		{
		public:
			/*============================
			*			CTOR
			============================*/
			PlayerShip();
			PlayerShip(int, int);
			~PlayerShip();

			/*============================
			*	  PUBLIC FUNCTIONS
			============================*/
			void MoveForward(const Engine::Math::Vector2&);
			void Render();
			void Update();
			void RotateLeft();
			void RotateRight();

		private:
			/*============================
			*		  MEMBERS
			============================*/
			Engine::Math::Vector2* m_position;
			float m_width;
			float m_height;
		};
	}
}

#endif // !_PLAYER_SHIP_HPP_