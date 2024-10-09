#pragma once

//------------------------------------------------------------------------------
class King : public APiece {
public:
	King();
	~King();

	void Release() override;

	MovableType IsMovable(const Board& board, int start_position[2],
		int destination_position[2]) const override;
};