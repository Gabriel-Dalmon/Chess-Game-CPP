#include "pch.h"


APiece::APiece(const std::type_info& type_info) : m_type(type_info), m_color(PieceColor::NONE)
{
}

int APiece::Initialize(PieceColor color)
{
	m_color = color;
	return 0;
}
