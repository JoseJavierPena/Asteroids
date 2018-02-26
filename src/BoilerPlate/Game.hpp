#pragma once
#ifndef _GAME_HPP_
#define _GAME_HPP_

//
#include <vector>

//
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "PlayerShip.hpp"
#include "Vector2.hpp"

namespace AsteroidsGame
{
	namespace EConsts
	{
		const Engine::Math::Vector2 null(0.f, 0.f);
	}

	class Game
	{
	public:
		/*============================
		*			STATES
		============================*/
		struct GameState
		{
			enum State
			{
				STOPPED = 0,
				RUNNING = 1,
			};
		};

		/*============================
		*			CTOR
		============================*/
		Game(int, int);
		~Game();

		/*============================
		*		PUBLIC FUNCTIONS
		============================*/
		void InitGame();
		void RenderGame();
		void Update(float);
		void FinishGame();

		/*============================
		*			MEMBERS
		============================*/
		std::vector<Asteroids::Entities::Asteroid*> m_asteroids;
		Asteroids::Entities::PlayerShip* m_ship;

	private:
		/*============================
		*		PUBLIC FUNCTIONS
		============================*/
		void CheckCollision();
		void DeleteAsteroids(Asteroids::Entities::Asteroid*);
		void CreateAsteroids(int, Asteroids::Entities::Asteroid::AsteroidSize::SIZE, Engine::Math::Vector2);
		void CreateRemainsAsteroid(Asteroids::Entities::Asteroid::AsteroidSize::SIZE, Engine::Math::Vector2);

		//TODO: For future assignment
		void ShowLives();

		/*============================
		*			MEMBERS
		============================*/
		int m_width;
		int m_height;
		int m_state;

		// TODO: For future assignment
		int m_lives;
		int m_score;
	};
}
#endif // !_GAME_HPP_