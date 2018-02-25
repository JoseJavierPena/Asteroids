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
			// TODO: Impulse not working
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
			glBegin(GL_POLYGON);
			glVertex2f(0.0f, 20.0f);
			glVertex2f(12.0f, -10.0f);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(-6.0f, -4.0f);
			glVertex2f(-12.0f, -10.0f);
			glEnd();

			if (m_thruster)
			{
				glBegin(GL_POLYGON);
				glVertex2f(6.0f, -4.0f);
				glVertex2f(0.0f, -16.0f);
				glVertex2f(-6.0f, -4.0f);
				glEnd();
			}
		}

		void PlayerShip::Update(float deltaTime)
		{
			if (!m_moving) m_thruster = false;

			// Clamp the speed
			ClampSpeed(Consts::MAX_SPEED_PLAYER);

			// Applying drag
			m_velocity = Engine::Math::Vector2(m_velocity.m_x * Consts::DRAG , m_velocity.m_y * Consts::DRAG);

			// Calculating new position
			Engine::Math::Vector2 pos = m_position + m_velocity;

			// Translation to new position
			Translate(pos);

			// Deletes all bullets if player is respawning
			if (m_inmune == false) EraseAllBullets();

			// Updating bullets
			for (int counter = 0; counter < static_cast<int>(m_bullets.size()); counter++)
			{
				m_bullets[counter]->Update(deltaTime);

				if (m_bullets[counter]->m_lifeTime >= 250)
				{
					DeleteBullet(m_bullets[counter]);
					break;
				}
			}

			// TODO: Redo this
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

		void PlayerShip::Shoot()
		{
			if (m_usedBullets == Consts::MAX_BULLETS) return;

			Bullet* kBullet = new Bullet(m_position, m_velocity, m_angle, m_width, m_height);
			m_bullets.push_back(kBullet);
			m_usedBullets++;
		}

		void PlayerShip::Respawn()
		{
			SetCollision(false);
			m_position = Engine::Math::Vector2(0.f);
			Reset();
			SetVelocity(Engine::Math::Vector2(0.f, 0.f));
		}

		void PlayerShip::CanCollide() const
		{}

		void PlayerShip::DeleteBullet(Bullet * kBullet)
		{
			m_bullets.erase(remove(m_bullets.begin(), m_bullets.end(), kBullet), m_bullets.end());
			delete kBullet;
			m_usedBullets--;
		}

		void PlayerShip::ClampSpeed(float max_speed)
		{
			float speed = std::fabsf(m_velocity.Lenght());

			if (speed > max_speed)
			{
				m_velocity = Engine::Math::Vector2((m_velocity.m_x / speed) * max_speed, (m_velocity.m_y / speed) * max_speed);
			}
		}

		void PlayerShip::Reset()
		{
			m_angle = 0.f;
			m_angleInRads = 0.f;
		}

		void PlayerShip::EraseAllBullets()
		{
			for (int counter = 0; counter < static_cast<int>(m_bullets.size()); counter++)
				DeleteBullet(m_bullets.at(counter));
		}
	}
}