#include "pch.h"

//------------------------------------------------------------------------------
Bishop::Bishop() : APiece(typeid(Bishop))
{
}

//------------------------------------------------------------------------------
Bishop::~Bishop()
{
}

//------------------------------------------------------------------------------
int Bishop::Initialize(PieceColor color)
{
	APiece::Initialize(color);
	return 0;
}

//------------------------------------------------------------------------------
void Bishop::Release()
{
}

//------------------------------------------------------------------------------
MovableType Bishop::IsMovable(const Board& board, int start_position[2],
	int destination_position[2]) const
{
	return MovableType::NOT_POSSIBLE;
}
