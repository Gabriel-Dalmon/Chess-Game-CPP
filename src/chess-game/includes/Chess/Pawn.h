#pragma once

//----------------------------------------------------------------------------------------------------------------
/** Using namespace to scope enum-values and avoid conflicts with other enums. */
namespace EPawn {
	typedef enum Directions {
		UP = 0, // Moves toward row 0.
		DOWN = 1, // Moves toward highest row value.
		NONE,
		PAWN_DIRECTIONS_COUNT
	} Direction;
}

//----------------------------------------------------------------------------------------------------------------
class Pawn : public APiece {
public:
	Pawn();
	~Pawn() override;

	int Initialize(PieceColor color);
	void Release() override;
	MovableType IsMovable(const Board& board, int start_position[2], int destination_position[2]) const override;

private:
	// NOTE: I added inline to these because they are supposed to be instructions wrappers that aren't meant to be called in many different scenario (mostly just in IsMovable). 
	// Not sure it is correct though.
	// I also assume having a lot of parameter in an inline function isn't an issue since it avoids function calls. That's why I prefered to compute row and columns externaly 
	// instead of passing them as arrays. But again could be incorrect.
	inline bool IsVerticalMovable(const APiece* const grid[BOARD_SIZE], int start_column, int start_row, int destination_row, int destination_index) const;
	inline bool IsCaptureMovable(const APiece& target_piece, int start_column, int start_row, int destination_column, int destination_row) const;
	inline bool IsEnPassantMovable(const APiece* const grid[BOARD_SIZE], int start_column, int start_row, int destination_column) const;

private:
	EPawn::Direction m_direction;
};