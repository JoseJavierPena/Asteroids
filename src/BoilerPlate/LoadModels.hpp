#pragma once
#ifndef _LOADMODELS_HPP_
#define _LOADMODELS_HPP_

#include <vector>
#include "Ship.hpp"
#include "Utilities.hpp"
#include "Vector2.hpp"

namespace Utilities
{
	class LoadModels
	{
	public:

		/*============================
		*			CTOR
		============================*/
		LoadModels();
		~LoadModels();

		/*============================
		*		PUBLIC FUNCTION
		============================*/
		std::vector<Asteroids::Entities::Ship*> Load(const int, const int);
	};
}
#endif // !_LOADMODELS_HPP_