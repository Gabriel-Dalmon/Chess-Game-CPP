#include "pch.h"

Knight::Knight() : APiece(typeid(Knight))
{
}

Knight::~Knight()
{
}

int Knight::Initialize(PieceColor color)
{
    APiece::Initialize(color);
    return 0;
}

void Knight::Release()
{
}

MovableType Knight::IsMovable(const Board& board, int start_position[2], int destination_position[2]) const
{
    return MovableType::NOT_POSSIBLE;
}
