#include "pch.h"

//------------------------------------------------------------------------------
King::King() : APiece(typeid(King))
{
}

//------------------------------------------------------------------------------
King::~King()
{
}

//------------------------------------------------------------------------------
void King::Release()
{
	return;
}

MovableType King::IsMovable(const Board& board, int start_position[2], int destination_position[2]) const
{
	return MovableType::NOT_POSSIBLE;
}
