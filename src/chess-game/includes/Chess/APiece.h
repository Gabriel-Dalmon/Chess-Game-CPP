#pragma once

//#define abstract_class class __declspec(novtable)
class __declspec(novtable) APiece {
public:
	APiece();
	virtual ~APiece() = 0;
	int Initialize(PieceColor color);

	virtual MovableType IsMovable(const Board& board, int start_position[2], int destination_position[2]) const = 0;
	bool IsPositionLocked() { return false; };

	// Getters/Setters
	inline PieceColor GetColor() const { return m_color; };
	inline bool IsSameColor(const APiece& piece) const { return piece.GetColor() == GetColor(); };
	const type_info& GetType() const { return m_type; };

	template<typename PieceType>
	inline bool Is() const { return m_type == typeid(PieceType); };

private:
	PieceColor m_color;
	const type_info& m_type;
};