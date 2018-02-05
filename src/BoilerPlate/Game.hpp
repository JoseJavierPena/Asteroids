#pragma once
#ifndef _GAME_HPP_
#define _GAME_HPP_

//#include "Color.hpp"
#include "Ship.hpp"
//#include "ChangeColor.hpp"
#include "LoadModels.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

namespace Asteroids
{
	class Game
	{
	public:
		/*============================
		*			STRUCT
		============================*/
		struct GameState
		{
			enum State
			{
				QUIT = 0,
				RUNNING = 1,
				//PAUSED = 2,
			};
		};

		/*============================
		*			CTOR
		============================*/
		Game();
		Game(int, int);
		~Game();

		/*============================
		*	  PUBLIC FUNCTIONS
		============================*/
		void Init();
		void Update(float);
		void Render();
		void ChangePlayerModel();
		int Finished();

		/*============================
		*		 PUBLIC MEMBERS
		============================*/
		Asteroids::Entities::Ship* m_player;

	private:

		/*============================
		*		 PRIVATE MEMBERS
		============================*/
		int m_width;
		int m_height;
		std::vector<Asteroids::Entities::Ship*> m_playerModels;
		int m_state;
		int m_modelsIndex;
	};
}

#endif // !_GAME_HPP_