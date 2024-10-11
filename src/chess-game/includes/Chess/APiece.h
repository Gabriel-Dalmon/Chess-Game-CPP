#pragma once

//#define abstract_class class __declspec(novtable)
//------------------------------------------------------------------------------
class __declspec(novtable) APiece {
public:
	APiece(const std::type_info& type_info);
	virtual ~APiece() = 0;

	int Initialize(PieceColor color);
	virtual void Release() = 0;

	virtual MovableType IsMovable(const Board& board, int start_position[2],
		int destination_position[2]) const = 0;
	bool IsPositionLocked() const { return false; };

	// Getters/Setters
	inline PieceColor GetColor() const { return m_color; };
	inline void SetColor(PieceColor color) { m_color = color; };
	inline bool IsSameColor(const APiece& piece) const { 
		return piece.GetColor() == GetColor(); };

	const type_info& GetType() const { return m_type; };
	template<typename PieceType>
	inline bool IsType() const { return m_type == typeid(PieceType); };

protected:
	const type_info& m_type;
private:
	PieceColor m_color;
};