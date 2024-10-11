#include "pch.h"

sfmlw::SquareShape::SquareShape()
{
}

sfmlw::SquareShape::~SquareShape()
{
}

int sfmlw::SquareShape::Initialize()
{
	m_p_shape = new sf::RectangleShape();
	return 0;
}

int sfmlw::SquareShape::Initialize(const int square_length, const sf::Color color)
{
	m_p_shape = new sf::RectangleShape({ square_length, square_length });
	m_p_shape->setFillColor(color);
	return 0;
}

void sfmlw::SquareShape::Release()
{
}
