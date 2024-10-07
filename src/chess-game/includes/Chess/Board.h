#pragma once

class Board {
public:
	Board();
	~Board();
	int Initialize();
	MoveInfo* Move(int start_position[2], int destination_position[2]);

	// Getters/Setters
	const APiece* const* GetGrid() const { return m_grid; };

private:
	int m_board_width;
	int m_board_height;
	const APiece* m_grid[BOARD_SIZE];
};