#include "Asteroid.hpp"

#include <GL\glew.h>
#include <SDL2\SDL_opengl.h>

namespace Asteroids
{
	namespace Entities
	{
		Asteroid::Asteroid(int width, int height)
		{
			m_position = Engine::Math::Vector2(Engine::Math::Vector2::origin);
			m_width = width;
			m_height = height;
		}

		void Asteroid::Render()
		{
			glLoadIdentity();

			// Translates a vector
			glTranslatef(m_position.m_x, m_position.m_y, 0.0f);

			// TODO: Create a better asteroid

			// Draws an asteroid
			glBegin(GL_LINE_LOOP);
			glVertex2f(50.0, 50.0);
			glVertex2f(50.0, -50.0);
			glVertex2f(-50.0, -50.0);
			glVertex2f(-50.0, 50.0);
			glEnd();
		}

		void Asteroid::Update(float deltaTime)
		{
			m_angle += 120 + deltaTime;
			Entity::Update(deltaTime);
		}
	}
}