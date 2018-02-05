#include "Game.hpp"

#include <SDL2\SDL_opengl.h>

namespace Asteroids
{
	Game::Game()
	{}

	// GAME CONSTRUCTOR
	Game::Game(int width, int height)
		: m_width(width)
		, m_height(height)
		, m_modelsIndex(0)
	{
		Utilities::LoadModels config;
		m_playerModels = config.Load(m_width, m_height);
		m_player = m_playerModels[m_playerModels.size() - 1];
	}

	// GAME DESTRUCTOR
	Game::~Game()
	{
		delete m_player;
		m_player = NULL;

		for (int i = 0; i < static_cast<int>(m_playerModels.size()) - 1; i++)
		{
			delete m_playerModels.at(i);
			m_playerModels.at(i) = NULL;
		}
	}

	// GAME INIT
	void Game::Init()
	{
		// Init game
		m_state = GameState::State::RUNNING;
	}

	// GAME UPDATE
	void Game::Update(float deltaTime)
	{
		if (m_state == GameState::RUNNING)
		{
			// Update player
			m_player->Update(deltaTime);
		}
	}

	// GAME RENDER
	void Game::Render()
	{
		if (m_state == GameState::RUNNING)
		{
			// Render player
			m_player->Render();
		}
	}

	// CHANGE PLAYER MODEL
	void Game::ChangePlayerModel()
	{
		int vectorSize = static_cast<int>(std::distance(m_playerModels.begin(), m_playerModels.end())) - 1;

		if (m_modelsIndex < vectorSize)
		{
			m_modelsIndex++;
		}
		else
		{
			m_modelsIndex = 0;
		}

		m_player = m_playerModels[m_modelsIndex];
	}

	// GAME FINISHED
	int Game::Finished()
	{
		if (m_state == GameState::State::QUIT)
			return 0;
		else 
			return GameState::RUNNING;
	}
}