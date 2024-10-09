#pragma once

//------------------------------------------------------------------------------
class Board {
public:
	Board();
	~Board();
	int Initialize();
	void Release();

	//--------------------------------------------------------------------------
	template<typename PieceType>
	PieceType* CreatePiece(PieceColor color, const int& column, const int& row)
	{
		static_assert(std::is_base_of<APiece, PieceType>::value,
			"PieceType must derive from APiece");
		PieceType* piece = new PieceType();
		piece->Initialize(color);
		m_grid[column + m_grid_width * row] = piece;
		return piece;
	}

	MoveInfo* Move(int start_position[2], int destination_position[2]);

	//--------------------------------------------------------------------------
	// Getters/Setters
	const APiece* const* GetGrid() const { return m_grid; };
	inline const int& GetGridWidth() const { return m_grid_width; };
	inline const int& GetGridHeight() const { return m_grid_height; };

//------------------------------------------------------------------------------
private:
	int m_grid_width;
	int m_grid_height;
	APiece* m_grid[BOARD_SIZE];

	APiece* m_en_passant_piece;
};