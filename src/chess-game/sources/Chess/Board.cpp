#include "pch.h"

Board::Board()
{
	m_board_width = BOARD_WIDTH;
	m_board_height = BOARD_HEIGHT;
}

Board::~Board()
{
}

int Board::Initialize()
{
}

MoveInfo* Board::Move(int start_position[2], int destination_position[2])
{
	const int piece_index = Helper::GetSquareIndex(start_position, BOARD_WIDTH);
	const APiece* p_piece = m_grid[piece_index];
	if (p_piece == nullptr) return nullptr;

	const APiece& piece = *p_piece;
	MovableType isMovable = piece.IsMovable(m_grid, start_position, destination_position);

	const int destination_index = destination_position[0] + destination_position[1] * BOARD_WIDTH;
	MoveInfo* p_move = new MoveInfo();

	switch (isMovable) {
		using enum MovableTypes;
	case MOVE:
		m_grid[destination_index] = m_grid[piece_index];
		m_grid[piece_index] = nullptr;
		break;
	case CAPTURE:
		p_move->captured_piece = m_grid[destination_index];
		break;
	case KINGSIDE_CASTLE:
	case QUEENSIDE_CASTLE:
	case NOT_POSSIBLE:
	case NOT_POSSIBLE_DISCOVERED_ATTACK:
	default:
		break;
	}
	return p_move;

	
}
