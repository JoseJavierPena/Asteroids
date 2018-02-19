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
			, m_velocity(Engine::Math::Vector2())
		{
			m_radius = 0.f;
			m_position = Engine::Math::Vector2(Engine::Math::Vector2::origin);

			m_width = width + 50;
			m_height = height + 50;
		}

		void PlayerShip::MoveForward()
		{
			// TODO: Redo position and move to new Class Entity
			m_thruster = true; 
			m_moving = true;

			ApplyImpulse();	
		}

		void PlayerShip::Render()
		{
			glLoadIdentity();

			// Wrap around 
			WrapAround(0.0f, -50.f, 50.f);

			// Translates a vector
			glTranslatef(m_position.m_x, m_position.m_y, 0.0f);

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

		void PlayerShip::Update(float deltaTime)
		{
			if (!m_moving) m_thruster = false;

			// Applying drag
			m_velocity = Engine::Math::Vector2(m_velocity.m_x * Constants::DRAG, m_velocity.m_y * Constants::DRAG);

			// Calculating new position
			Engine::Math::Vector2 pos = m_position + m_velocity;

			Entity::Update(deltaTime);
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