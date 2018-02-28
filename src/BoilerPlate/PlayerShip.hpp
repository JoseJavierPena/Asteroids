#pragma once
#ifndef _PLAYER_SHIP_HPP_
#define _PLAYER_SHIP_HPP_

//
#include <vector>

//
#include "Vector2.hpp"
#include "Entity.hpp"
#include "MathUtilities.hpp"
#include "Constants.hpp"
#include "Bullet.hpp"

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
			void Shoot();
			void Respawn();
			bool CanCollide() const;
			void Clean() { EraseAllBullets(); };
			void DeleteBullet(Bullet* );

			//
			void SetCollision(bool status) { m_inmune = status; };
			void SetVelocity(Engine::Math::Vector2 v) { m_velocity = v; };

			/*============================
			*		  MEMBERS
			============================*/
			std::vector<Bullet*> m_bullets;

		private:
			/*============================
			*	  PRIVATE FUNCTIONS
			============================*/
			void ApplyImpulse() { m_velocity += Impulse(); };
			void ClampSpeed(float) override;
			void Reset();
			void EraseAllBullets();

			/*============================
			*		PRIVATE MEMBERS
			============================*/
			Engine::Math::Vector2 m_velocity;
			float m_mass;
			float m_angle;
			bool m_thruster;
			bool m_moving;
			bool m_inmune;
			int m_usedBullets;
			float m_currentSpeed;
		};
	}
}
#endif // !_PLAYER_SHIP_HPP_