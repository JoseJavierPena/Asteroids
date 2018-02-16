#include "PlayerShip.hpp"

#include <GL\glew.h>
#include <SDL2\SDL_opengl.h>

namespace Asteroids
{
	namespace Entities
	{
		PlayerShip::PlayerShip(int width, int height)
			: m_angle(0.0f)
			, m_thruster(false)
			, m_moving(false)
		{
			m_position = new Engine::Math::Vector2(Engine::Math::Vector2::origin);

			maxWidth = width / 2.0f;
			minWidth = -width / 2.0f;

			maxHeight = height / 2.0f;
			minHeight = -height / 2.0f;
		}

		void PlayerShip::MoveForward(/*Engine::Math::Vector2 a*/ float x, float y)
		{
			// TODO: Redo position and move to new Class Entity
			/*float x = m_position->m_x + a.m_x;
			float y = m_position->m_y + a.m_y;*/
			m_thruster = true; 
			m_moving = true;

			m_position->m_x += Asteroids::Entities::Entity::Wraparound(x, minWidth, maxWidth);
			m_position->m_y += Asteroids::Entities::Entity::Wraparound(y, minHeight, maxHeight);
		}

		void PlayerShip::Render()
		{
			glLoadIdentity();

			// Translates a vector
			glTranslatef(m_position->m_x, m_position->m_y, 0.0f);

			// Rotate the ship
			glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

			// Draws the ship
			glBegin(GL_LINE_LOOP);
			glVertex2f(0.0f, 20.0f);
			glVertex2f(12.0f, -10.0f);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(-6.0f, -4.0f);
			glVertex2f(-12.0f, -10.0f);
			glEnd();

			if (m_thruster)
			{
				glBegin(GL_LINE_LOOP);
				glVertex2f(6.0f, -4.0f);
				glVertex2f(0.0f, -16.0f);
				glVertex2f(-6.0f, -4.0f);
				glEnd();
			}
		}

		// TODO
		void PlayerShip::Update()
		{
			if (!m_moving) m_thruster = false;

		}

		void PlayerShip::RotateLeft()
		{
			float new_angle = 5.0f;
			m_angle += new_angle;
			Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle);
		}

		void PlayerShip::RotateRight()
		{
			float new_angle = -5.0f;
			m_angle += new_angle;
			Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle);
		}
	}
}