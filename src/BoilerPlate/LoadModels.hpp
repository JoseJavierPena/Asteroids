#pragma once
#ifndef _LOADMODELS_HPP_
#define _LOADMODELS_HPP_

#include <vector>
#include "Ship.hpp"
#include "Utilities.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
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

		/*============================
		*			MEMBERS
		============================*/
		std::string const fileName = "models";
	};
}
#endif // !_LOADMODELS_HPP_