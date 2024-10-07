#pragma once

// Macros
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
#define BOARD_SIZE BOARD_WIDTH * BOARD_HEIGHT

// Forward declarations
class APiece;
class Pawn;
class Rook;
class Knight;
class Bishop;
class Queen;
class King;

class Board;

// Enums
typedef enum PieceColors {
	WHITE = 0,
	BLACK = 1,
	PIECE_COLORS_COUNT
} PieceColor;

typedef enum MovableTypes {
	NOT_POSSIBLE,
	NOT_POSSIBLE_DISCOVERED_ATTACK,
	MOVE,
	CAPTURE,
	KINGSIDE_CASTLE,
	QUEENSIDE_CASTLE,
	EN_PASSANT,
	PROMOTION,
	CHECK,
	CHECKMATE,
	MOVABLE_TYPES_COUNT
} MovableType;

struct MoveInfo {
	APiece* captured_piece = nullptr;
	// flags: isEnPassant, isPromotion
};

// Includes
#include "Chess/APiece.h"
#include "Chess/Pawn.h"
#include "Chess/Rook.h"
#include "Chess/Knight.h"
#include "Chess/Bishop.h"
#include "Chess/Queen.h"
#include "Chess/King.h"

#include "Chess/Board.h"