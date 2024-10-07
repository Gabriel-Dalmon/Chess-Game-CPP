#pragma once

class Rook : public APiece {
public:
	Rook();
	~Rook();

	int Initialize(PieceColor color);
	void Release() override;

	MovableType IsMovable(const Board& board, int start_position[2], int destination_position[2]) const override;
};