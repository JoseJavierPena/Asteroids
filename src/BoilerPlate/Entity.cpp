#include "Entity.hpp"


// TODO: Redo this part, move it from asteroids and ship to here
namespace Asteroids
{
	namespace Entities
	{
		Entity::Entity()
		{}

		Entity::Entity(int width, int height)
		{
			m_position = new Engine::Math::Vector2(Engine::Math::Vector2::origin);
			m_mass = 0.5f;
		}

		Entity::~Entity()
		{}

		float Entity::Wraparound(float x_axis, float min, float max)
		{
			// TODO: Redo warp or wraparound function
			if (x_axis < min) return max - (min - x_axis);
			if (x_axis > max) return min + (x_axis - max);
			/*
			if (x < min) return -x;
			if (x > max) return -x;*/
			return x_axis;
		}

		void Entity::Update()
		{}

		void Entity::Render()
		{}
	}
}