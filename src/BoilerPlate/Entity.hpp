#pragma once
#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

//
#include "Vector2.hpp"
#include <iostream>
#include "MathUtilities.hpp"

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
			virtual void Translate(Engine::Math::Vector2 pos) { m_position = pos; };
			bool IsColliding(Entity*);

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