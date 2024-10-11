#pragma once

namespace sfmlw {

class AShape {
public:
	AShape() {};
	virtual ~AShape() = 0;

	virtual int Initialize() = 0;
	void Release();

	inline const void SetPosition(float x, float y) const { m_p_shape->setPosition({ x, y }); };
	inline const sf::Shape* GetSFMLShape() const { return m_p_shape; }

protected:
	sf::Shape* m_p_shape;
};

}