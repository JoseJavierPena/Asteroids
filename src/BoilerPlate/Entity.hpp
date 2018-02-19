#pragma once
#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "Vector2.hpp"
#include <iostream>
#include "MathUtilities.hpp"

namespace Constants
{
	const float THRUST = 1.5;
	const float ANGLE_OFFSET = 90.0f;
	const float DRAG = 0.9f;
}

namespace Asteroids
{
	namespace Entities
	{
		class Entity
		{
		public:
			/*============================
			*			CTOR
			============================*/
			Entity();
			Entity(int, int);

			/*============================
			*		PUBLIC FUNCTIONS
			============================*/
			void Update(float);
			void Render();
			float WrapAround(float, float, float);

		protected:
			/*============================
			*	  PRIVATE FUNCTIONS
			============================*/
			Engine::Math::Vector2 Impulse();
			virtual void ApplyImpulse() { m_velocity += Impulse(); };

			/*============================
			*			MEMBERS
			============================*/
			Engine::Math::Vector2 m_position;
			Engine::Math::Vector2 m_velocity;
			int m_width;
			int m_height;
			float m_maxWidth;
			float m_minWidth;
			float m_maxHeight;
			float m_minHeight;
			float m_angleInRads;
			float m_angle;
			float m_mass;
			float m_radius;
		};
	}
}
#endif // !_ENTITY_HPP_