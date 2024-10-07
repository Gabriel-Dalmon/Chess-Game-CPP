#pragma once

class Knight : public APiece {
public:
	Knight();
	~Knight();

	int Initialize(PieceColor color);
	void Release() override;

	MovableType IsMovable(const Board& board, int start_position[2], int destination_position[2]) const override;
};