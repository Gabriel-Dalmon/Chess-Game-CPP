#pragma once
#ifdef _SFML_VERSION

class SFMLRenderer {
public:
	SFMLRenderer();
	~SFMLRenderer();

	int Initialize();
	void Release();

	void Render(const Board& board);
private:
	sf::RenderWindow window;
};

#endif