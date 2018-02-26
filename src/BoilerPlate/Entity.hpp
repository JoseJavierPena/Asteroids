#pragma once
#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

//
#include <vector>

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
			Entity() { m_position = Engine::Math::Vector2(); };
			Entity(int, int);

			/*============================
			*		PUBLIC FUNCTIONS
			============================*/
			void Update(float);
			void Render(unsigned int, Engine::Math::Vector2, float angle);
			float WrapAround(float, float, float);
			virtual void ApplyImpulse() = 0;
			virtual void Translate(Engine::Math::Vector2 pos) { m_position = pos; };
			bool IsColliding(Entity*);
			template<typename T>
			T Random(T min, T max) { return static_cast<T>(min + (rand() % (int)(max - min + 1))); }

		protected:
			/*============================
			*	  PROTECTED FUNCTIONS
			============================*/
			Engine::Math::Vector2 Impulse();
			void RandomPos(float, float);
			virtual void ClampSpeed(float);

			/*============================
			*			MEMBERS
			============================*/
			Engine::Math::Vector2 m_position;
			Engine::Math::Vector2 m_velocity;
			std::vector<Engine::Math::Vector2> m_points;
			int m_width;
			int m_height;
			float m_maxWidth = 1136.0f;
			float m_minWidth;
			float m_maxHeight = 640.0f;
			float m_minHeight;
			float m_angleInRads;
			float m_angle;
			float m_mass;
			float m_radius;
		};
	}
}
#endif // !_ENTITY_HPP_