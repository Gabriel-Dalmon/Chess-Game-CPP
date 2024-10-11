#pragma once

namespace sfmlw {

class SquareShape : public AShape {
public:
	SquareShape();
	~SquareShape() override;

	int Initialize() override;
	int Initialize(const int square_length, const sf::Color color);

	void Release();

	unsigned int GetLength() const { return static_cast<sf::RectangleShape*>(m_p_shape)->getSize().x; }
};

}