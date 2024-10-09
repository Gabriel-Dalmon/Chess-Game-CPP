#include "pch.h"

//------------------------------------------------------------------------------
Queen::Queen() : APiece(typeid(Queen))
{
}

//------------------------------------------------------------------------------
Queen::~Queen()
{
}

//------------------------------------------------------------------------------
void Queen::Release()
{
}

MovableType Queen::IsMovable(const Board& board, int start_position[2], int destination_position[2]) const
{
	return MovableType::NOT_POSSIBLE;
}
