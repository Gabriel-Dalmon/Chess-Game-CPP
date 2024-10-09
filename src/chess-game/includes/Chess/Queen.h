#pragma once

//------------------------------------------------------------------------------
class Queen : public APiece {
public:
	Queen();
	~Queen();

	void Release() override;

	MovableType IsMovable(const Board& board, int start_position[2],
		int destination_position[2]) const override;
};