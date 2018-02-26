#include "Asteroid.hpp"

#include <GL\glew.h>
#include <SDL2\SDL_opengl.h>

namespace Asteroids
{
	namespace Entities
	{
		// TODO: Redo this
		Asteroid::Asteroid(const int width, const int height)
		{
			m_position = Engine::Math::Vector2(Engine::Math::Vector2::origin);
			m_width = width;
			m_height = height;
			m_size = AsteroidSize::SIZE::BIG;
			m_angleInRads = Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle + Consts::ANGLE_OFFSET);
			m_width = width + 50;
			m_height = height + 50;
			m_sizeFactor = (int)m_size + 1;
			//SizeFactor();
			m_velocity = Engine::Math::Vector2();
			RandomPos(m_height, m_width);
			//RandomPoints();
		}

		// TODO: Redo this
		Asteroid::Asteroid(AsteroidSize::SIZE size, Engine::Math::Vector2 pos, const int width, const int height)
		{
			m_points.resize(Consts::MAX_POINTS);
			m_size = size;
			m_position = pos;
			//RandomPoints();
			//RandomAngle(2, 24);
			m_angleInRads = Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle + Consts::ANGLE_OFFSET);
			m_width = width;
			m_height = height;
			//SizeFactor();
			m_velocity = Engine::Math::Vector2();
		}

		void Asteroid::Render()
		{
			glLoadIdentity();

			// Translates a vector
			glTranslatef(m_position.m_x, m_position.m_y, 0.0f);

			glRotatef(m_angle, 0.0f, 0.0f, 0.0f);

			// TODO: Create a better asteroid
			// Draws an asteroid
			glBegin(GL_LINE_LOOP);

			std::vector<Engine::Math::Vector2>::iterator it = m_points.begin();
			for (; it != m_points.end(); ++it)
				glVertex2f((*it).m_x, (*it).m_y);

			glEnd();

			//Entities::Entity::Render(GL_POLYGON, m_position, m_color, m_angle);
		}

		void Asteroid::Update(float deltaTime)
		{
			/*m_angle += 120 + deltaTime;
			Entity::Update(deltaTime);*/

			// New pos
			ApplyImpulse();

			if (m_size == AsteroidSize::SIZE::SMALL)
				ClampSpeed(Consts::MAX_SPEED_SMALL_ASTEROID);
			else if (m_size == AsteroidSize::SIZE::MEDIUM)
				ClampSpeed(Consts::MAX_SPEED_MED_ASTEROID);
			else if (m_size == AsteroidSize::SIZE::BIG)
				ClampSpeed(Consts::MAX_SPEED_BIG_ASTEROID);

			Engine::Math::Vector2 newPos = m_position + m_velocity;

			// Translation to newPos
			Translate(newPos);
		}
	}
}