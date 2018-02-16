#pragma once
#ifndef _PLAYER_SHIP_HPP_
#define _PLAYER_SHIP_HPP_

#include "Vector2.hpp"
#include "Entity.hpp"
#include "MathUtilities.hpp"

namespace Asteroids
{
	namespace Entities
	{
		class PlayerShip : Entity
		{
		public:
			/*============================
			*			CTOR
			============================*/
			PlayerShip(int, int);

			/*============================
			*	  PUBLIC FUNCTIONS
			============================*/
			void MoveForward(/*Engine::Math::Vector2 a*/ float x, float y);
			void Render();
			void Update();
			void RotateLeft();
			void RotateRight();

		private:
			/*============================
			*		  MEMBERS
			============================*/
			Engine::Math::Vector2* m_position;
			float maxWidth;
			float maxHeight;
			float minWidth;
			float minHeight;
			float m_mass;
			float m_angle;
			bool m_thruster;
			bool m_moving;
		};
	}
}
#endif // !_PLAYER_SHIP_HPP_