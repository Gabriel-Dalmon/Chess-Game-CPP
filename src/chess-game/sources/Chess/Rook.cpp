#include "pch.h"

//------------------------------------------------------------------------------
Rook::Rook() : APiece(typeid(Rook))
{
}

//------------------------------------------------------------------------------
Rook::~Rook()
{
}

//------------------------------------------------------------------------------
int Rook::Initialize(PieceColor color)
{
	APiece::Initialize(color);
	return 0;
}

//------------------------------------------------------------------------------
void Rook::Release()
{
}

//------------------------------------------------------------------------------
MovableType Rook::IsMovable(const Board& board, int start_position[2],
	int destination_position[2]) const
{
	return MovableType::NOT_POSSIBLE;
}