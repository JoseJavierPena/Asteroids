#pragma once
#ifndef _COLOR_HPP_
#define _COLOR_HPP_

#include "Vector3.hpp"

namespace Colors
{
	static class Color
	{
	public:
		/*============================
		*			CTOR
		============================*/
		Color();
		Color(int, int, int);

		/*============================
		*			MEMBERS
		============================*/
		int m_alpha;
		Engine::Math::Vector3 m_color;
	};
}
#endif // !_COLOR_HPP_