#include "Game.hpp"

// OpgenGL includes
#include "IncludeGL.hpp"

namespace AsteroidsGame
{
	Game::Game(int width, int height)
		: m_width(width), m_height(height)
		, m_lives(3), m_score(0)
	{};

	Game::~Game()
	{
		delete m_ship;
		m_ship = NULL;
	};

	void Game::InitGame()
	{
		m_state = GameState::State::RUNNING;

		// Creating the asteroids
		CreateAsteroids(1, Asteroids::Entities::Asteroid::AsteroidSize::SIZE::BIG, EConsts::null);
	};

	void Game::RenderGame()
	{
		if (m_state == GameState::State::RUNNING)
		{
			m_ship->Render();

			// Lives code goes here
			//
		}

		for (int counter = 0; counter < static_cast<int>(m_asteroids.size()); counter++)
			m_asteroids[counter]->Render();
	};

	void Game::Update(float deltaTime)
	{
		// Lives code goes here
		//

		if (m_state == GameState::State::RUNNING)
		{
			// Update player in game object
			m_ship->Update(deltaTime);

			//
			CheckCollision();

			// Update asteroids
			CreateAsteroids(1, Asteroids::Entities::Asteroid::AsteroidSize::SIZE::BIG, EConsts::null);

			//
		}

		//
		for (int counter = 0; counter < static_cast<int>(m_asteroids.size()); counter++)
			m_asteroids.at(counter)->Update(deltaTime);
	};

	void Game::FinishGame()
	{
		// Stop game object
		m_state = GameState::State::STOPPED;
	};

	void Game::CheckCollision()
	{
		// Checking if the ship is not colliding
		if (!m_ship->CanCollide()) return;

		bool bulletHit = false;
	
		// Checking collision with the asteroids
		for (auto temp : m_asteroids)
		{
			Asteroids::Entities::Asteroid* kAsteroid = dynamic_cast<Asteroids::Entities::Asteroid*>(temp);

			if (kAsteroid)
			{
				//TODO: Redo
				// Checking player collision
				//if (m_ship->IsColliding(kAsteroid))
				//{
				//	// Getting size and position for asteroids
				//	Asteroids::Entities::Asteroid::AsteroidSize::SIZE currentSz = kAsteroid->GetSize();
				//	Engine::Math::Vector2 position = temp->GetPosition();

				//	// Deleting asteroids
				//	DeleteAsteroids(temp);

				//	// Creating remains of the asteroids
				//	CreateRemainsAsteroid(currentSz, position);

				//	// Respawn player ship
				//	m_ship->Respawn();

				//	//Player lives code goes here
				//	//

				//	// Score code goes here
				//	//

				//	break;
				//}

				// Checking bullet collision
				for (int counter = 0; counter < static_cast<int>(m_ship->m_bullets.size()); counter++)
				{
					//TODO: Redo
					//if (m_ship->m_bullets[counter]->IsColliding(kAsteroid))
					//{
					//	// Getting size for remains of the asteroids
					//	Asteroids::Entities::Asteroid::AsteroidSize::SIZE currentSize = kAsteroid->GetSize();
					//	Engine::Math::Vector2 currentPosition = kAsteroid->GetPosition();

					//	//

					//	//Deleting asteroid
					//	DeleteAsteroids(temp);

					//	// Deleting bullet
					//	m_ship->DeleteBullet(m_ship->m_bullets[counter]);

					//	//Creating remains of the asteroids
					//	CreateRemainsAsteroid(currentSize, currentPosition);
					//	bulletHit = true;
					//}
				}

				if (bulletHit == true)
					break;
			}
		}
	};

	void Game::CreateAsteroids(int amount, Asteroids::Entities::Asteroid::AsteroidSize::SIZE size, Engine::Math::Vector2 pos)
	{
		if (pos == EConsts::null)
		{
			for (int counter = 0; counter < amount; counter++)
			{
				Asteroids::Entities::Asteroid* kAsteroid = new Asteroids::Entities::Asteroid(m_width, m_height);
				m_asteroids.push_back(kAsteroid);
			}
			return;
		}
		else
		{
			for (int counter = 0; counter < amount; counter++)
			{
				Asteroids::Entities::Asteroid* kAsteroid = new Asteroids::Entities::Asteroid(size, pos, m_width, m_height);
				m_asteroids.push_back(kAsteroid);
			}
		}
	};

	void Game::CreateRemainsAsteroid(Asteroids::Entities::Asteroid::AsteroidSize::SIZE size, Engine::Math::Vector2 pos)
	{
		if (size == Asteroids::Entities::Asteroid::AsteroidSize::SIZE::SMALL) return;

		else if (size == Asteroids::Entities::Asteroid::AsteroidSize::SIZE::MEDIUM)
			CreateAsteroids(2, Asteroids::Entities::Asteroid::AsteroidSize::SIZE::SMALL, pos);

		else if (size == Asteroids::Entities::Asteroid::AsteroidSize::SIZE::BIG)
			CreateAsteroids(2, Asteroids::Entities::Asteroid::AsteroidSize::SIZE::BIG, pos);
	};
}