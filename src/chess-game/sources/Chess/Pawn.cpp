#include "pch.h"

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
}

int Pawn::Initialize(PieceColor color)
{
	return 0;
}

//----------------------------------------------------------------------------------------------------------------
MovableType Pawn::IsMovable(const Board& board, int start_position[2], int destination_position[2])
{
	//------------------------------------------------------------------------------------------------------------
	/** Checks if the piece is not under a discovered attack. */
	if (IsPositionLocked()) return MovableType::NOT_POSSIBLE_DISCOVERED_ATTACK;

	//------------------------------------------------------------------------------------------------------------
	/** Useful recurrent variables */
	const int start_index = Helper::GetSquareIndex(start_position, BOARD_WIDTH);
	const int destination_index = Helper::GetSquareIndex(destination_position, BOARD_WIDTH);
	const int start_column = start_position[0];
	const int destination_column = destination_position[0];
	const int start_row = start_position[1];
	const int destination_row = destination_position[1];
	const APiece* const* grid = board.GetGrid();

	//------------------------------------------------------------------------------------------------------------
	/** VERTICAL MOVE CHECK */
	const bool is_vertical_move_only = start_column == destination_column;
	if (is_vertical_move_only) [[likely]] {
		const bool is_vertical_movable = IsVerticalMovable(grid, start_column, start_row, destination_row, destination_index);
		if (is_vertical_movable) return MovableType::MOVE;
	}
	//------------------------------------------------------------------------------------------------------------
	/** CAPTURE MOVE CHECK */
	else {
		const APiece* p_destination_square = grid[destination_index];
		const bool is_destination_occupied = p_destination_square != nullptr;
		//--------------------------------------------------------------------------------------------------------
		/** NORMAL CAPTURE MOVE CHECK */
		if (is_destination_occupied) [[likely]] {
			const bool is_capture_movable = IsCaptureMovable(*p_destination_square, start_column, start_row, destination_column, destination_row);
			if (is_capture_movable) return MovableType::CAPTURE;
		}
		//--------------------------------------------------------------------------------------------------------
		/** EN PASSANT CAPTURE MOVE CHECK */
		else {
			const bool is_en_passant_movable = IsEnPassantMovable(grid, start_column, start_row, destination_column);
			if (is_en_passant_movable) return MovableType::EN_PASSANT;
		}
	}
	return MovableType::NOT_POSSIBLE;
}

//----------------------------------------------------------------------------------------------------------------
inline bool Pawn::IsVerticalMovable(const APiece* const grid[BOARD_SIZE], int start_column, int start_row, int destination_row, int destination_index)
{
	const bool is_destination_occupied = grid[destination_index] != nullptr;
	if (is_destination_occupied) return false;

	const int normal_move_row = start_row + m_direction;
	const bool is_normal_move = destination_row == normal_move_row;
	if (is_normal_move) return true;

	const bool is_start_move = destination_row == start_row + (2 * m_direction);
	if (is_start_move == false) return false;

	const int normal_move_index = start_column + normal_move_row * BOARD_WIDTH;
	const bool is_normal_move_square_occupied = grid[normal_move_index] != nullptr;
	if (is_normal_move_square_occupied) return false;
	return true;
}

//----------------------------------------------------------------------------------------------------------------
/** 
* @param target_piece - the piece to capture (must not be nullptr)
*/
inline bool Pawn::IsCaptureMovable(const APiece& target_piece, int start_column, int start_row, int destination_column, int destination_row)
{
	//------------------------------------------------------------------------------------------------------------
	/** Check capture move pattern. */
	const int normal_move_row = start_row + m_direction;
	const bool capture_vertical_constraint = destination_row == normal_move_row;
	if (capture_vertical_constraint == false) return false;

	const bool capture_horizontal_constraint = start_column + 1 == destination_column || start_column - 1 == destination_column;
	if (capture_horizontal_constraint == false) return false;

	//------------------------------------------------------------------------------------------------------------
	/** Check piece at target position is capturable. */
	if (IsSameColor(target_piece)) return false;

	if (target_piece.Is<King>()) return false;
	return true;
}

//----------------------------------------------------------------------------------------------------------------
// TODO: add a way to disable en passant if not used when available.
inline bool Pawn::IsEnPassantMovable(const APiece* const grid[BOARD_SIZE], int start_column, int start_row, int destination_column)
{
	//------------------------------------------------------------------------------------------------------------
	/** Check en passant move pattern. */
	const bool en_passant_row_constraint = start_row == (m_direction == PawnDirection::DOWN) * BOARD_HEIGHT - m_direction * 4;
	if (en_passant_row_constraint == false) return false;

	const bool en_passant_horizontal_constraint = start_column + 1 == destination_column || start_column - 1 == destination_column;
	if (en_passant_horizontal_constraint == false) return false;

	//------------------------------------------------------------------------------------------------------------
	/** Check piece at target position is capturable with en passant. */
	const APiece* p_side_square = grid[destination_column + start_row * BOARD_WIDTH];
	if (p_side_square == nullptr) return false;

	const APiece& target_piece = *p_side_square;
	if (IsSameColor(target_piece)) return false;

	if (target_piece.Is<Pawn>()) return false;
	return true;
}
