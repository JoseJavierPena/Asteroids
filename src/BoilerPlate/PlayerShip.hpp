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
			void MoveForward();
			void Render();
			void Update(float);
			void RotateLeft();
			void RotateRight();
			void NotMoving() { m_moving = false; };

		private:
			/*============================
			*	  PRIVATE FUNCTIONS
			============================*/
			void ApplyImpulse() { m_velocity += Impulse(); };

			/*============================
			*		  MEMBERS
			============================*/
			Engine::Math::Vector2 m_velocity;;
			float m_mass;
			float m_angle;
			bool m_thruster;
			bool m_moving;
		};
	}
}
#endif // !_PLAYER_SHIP_HPP_