#include "Ship.hpp"

#include <SDL2\SDL_opengl.h>

namespace Asteroids
{
	namespace Entities
	{
		Asteroids::Entities::Ship::Ship()
		{}

		// CONSTRUCTOR
		Asteroids::Entities::Ship::Ship(const std::vector<Engine::Math::Vector2> points, const int width, const int height)
			: m_velocity(Engine::Math::Vector2())
		{
			m_points = points;
			m_radius = 0.0f;
			m_angle = 0.0f;
			m_angleRad = Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle + m_angle_offset);
			m_width = width + 50;
			m_width = height + 50;
		}

		// DESTRUCTOR
		Asteroids::Entities::Ship::~Ship()
		{}

		void Ship::Render(unsigned int mode, Engine::Math::Vector2 position, float angle)
		{
			m_angleRad = 0.0f;

			// Reset Matrix
			glLoadIdentity();

			// Translation to current position
			glTranslatef(position.m_x, position.m_y, 0.0f);

			// Rotation to current angle
			glRotatef(angle, 0.0f, 0.0f, 1.0f);

			// Rendering
			glBegin(GL_LINE_LOOP);
			for (auto temp : m_points)
				glVertex2f(temp.m_x, temp.m_y);

			glEnd();
		}

		// TODO!!!!!!!!!!!!!!!!!!!
		// MOVE
		void Ship::Move()
		{
			// Move forward
			MoveForward();

			// Move left
			MoveLeft();

			// Move right
			MoveRight();
		}
		// TODO!!!!!!!!!!!!!!!!!!!

		// MOVE FORWARD
		void Ship::MoveForward()
		{
			ApplyImpulse();
		}

		// MOVE LEFT
		void Ship::MoveLeft()
		{
			Rotate(-5.0f);
		}

		// MOVE RIGHT
		void Ship::MoveRight()
		{
			Rotate(5.0f);
		}

		// RENDER
		void Ship::Render()
		{
			m_angleRad = Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle + m_angle_offset);

			Render(GL_LINE_LOOP, m_position, m_angle);
		}

		// RENDER
		void Ship::Render(unsigned int mode, std::vector<Engine::Math::Vector2> points, Engine::Math::Vector2 position)
		{
			// Reset matrix
			glLoadIdentity();

			// Translation to current position
			glTranslatef(position.m_x, position.m_y, 0.f);

			// Keep angle offset
			glRotatef(0.f, 0.f, 0.f, 1.f);

			glBegin(GL_LINE_LOOP);
			for (auto temp : points)
				glVertex2f(temp.m_x, temp.m_y);

			glEnd();
		}

		// UPDATE
		void Ship::Update(float deltaTime)
		{
			// Calculating new position
			Engine::Math::Vector2 pos = m_position + m_velocity;

			// Translation to new position
			Translate(pos);	
		}

		// APPLY IMPULSE
		void Ship::ApplyImpulse()
		{
			m_velocity += Impulse();
		}

		// IMPULSE
		Engine::Math::Vector2 Ship::Impulse()
		{
			float impulse = (m_thrust / m_mass);
			float x = impulse * std::cosf(m_angleRad);
			float y = impulse * std::sinf(m_angleRad);

			return Engine::Math::Vector2(x, y);
		}

		// ROTATE
		void Ship::Rotate(float angl)
		{
			// Updating angle
			m_angle += angl;
			m_angleRad = Engine::Math::MathUtilities::ConvertDegreesToRad(m_angle + m_angle_offset);
		}
		
	}
}