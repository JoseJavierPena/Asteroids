#include "Color.hpp"

namespace Colors 
{
	Color::Color()
	{
		m_color.m_x = 0;
		m_color.m_y = 0;
		m_color.m_z = 0;
		m_alpha = 255;
	}

	Color::Color(int re, int gre, int blu)
	{
		m_color.m_x = re;
		m_color.m_y = gre;
		m_color.m_z = blu;
		m_alpha = 255;
	}

	Color::~Color()
	{}
}