#pragma once
#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "Vector2.hpp"

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
			~Entity();

			/*============================
			*		PUBLIC FUNCTIONS
			============================*/
			void Wraparound(float, float, float);
			void Update();
			void Render();

		private:
			/*============================
			*			MEMBERS
			============================*/
			Engine::Math::Vector2* m_position;
			float m_maxWidth;
			float m_minWidth;
			float m_maxHeight;
			float m_minHeight;
			float m_mass;
			float m_radius;
		};
	}
}
#endif // !_ENTITY_HPP_