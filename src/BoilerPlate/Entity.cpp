#include "Entity.hpp"


// TODO: Redo this part, move it from asteroids and ship to here
namespace Asteroids
{
	namespace Entities
	{
		Entity::Entity() {}

		Entity::Entity(int width, int height)
		{
			m_position = Engine::Math::Vector2(Engine::Math::Vector2::origin);
			m_mass = 0.5f;
			m_angleInRads = Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle + Constants::ANGLE_OFFSET);

			m_maxWidth = width / 2.0f;
			m_minWidth = -width / 2.0f;
			
			m_maxHeight = height / 2.0f;
			m_minHeight = -height / 2.0f;
		}

		float Entity::WrapAround(float x_axis, float min, float max)
		{
			if (x_axis < min) return max - (min - x_axis);
			if (x_axis > max) return min + (x_axis - max);

			return x_axis;
		}

		Engine::Math::Vector2 Entity::Impulse()
		{
			float impulse = (Constants::THRUST / m_mass);
			float x = impulse * std::cosf(m_angleInRads);
			float y = impulse * std::sinf(m_angleInRads);

			return Engine::Math::Vector2(x, y);
		}

		void Entity::Update(float deltaTime)
		{
			m_position.m_x += m_velocity.m_x * static_cast<float>(deltaTime);
			m_position.m_y += m_velocity.m_y * static_cast<float>(deltaTime);

			m_position.m_x = WrapAround(m_position.m_x, m_minWidth, m_maxWidth);
			m_position.m_y = WrapAround(m_position.m_y, m_minHeight, m_maxHeight);
		}

		void Entity::Render()
		{}
	}
}